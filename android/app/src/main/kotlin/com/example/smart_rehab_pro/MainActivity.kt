package com.example.smart_rehab_pro

import android.os.Build
import android.content.pm.PackageManager
import android.os.Bundle
import android.util.Log
import android.bluetooth.BluetoothDevice
import io.flutter.embedding.android.FlutterActivity
import io.flutter.embedding.engine.FlutterEngine
import io.flutter.plugin.common.EventChannel
import io.flutter.plugin.common.MethodChannel

import com.xsens.dot.android.sdk.DotSdk
import com.xsens.dot.android.sdk.events.DotData
import com.xsens.dot.android.sdk.models.DotDevice
import com.xsens.dot.android.sdk.models.DotPayload
import com.xsens.dot.android.sdk.models.FilterProfileInfo
import com.xsens.dot.android.sdk.utils.DotScanner

import com.xsens.dot.android.sdk.interfaces.DotDeviceCallback
import com.xsens.dot.android.sdk.interfaces.DotMeasurementCallback
import com.xsens.dot.android.sdk.interfaces.DotScannerCallback
import com.xsens.dot.android.sdk.interfaces.DotSyncCallback

import java.util.ArrayList
import java.util.HashMap

class MainActivity: FlutterActivity(),
    DotDeviceCallback, DotMeasurementCallback, DotScannerCallback, DotSyncCallback {

    private var eventSink: EventChannel.EventSink? = null
    private var mDotScanner: DotScanner? = null

    // Force uppercase MAC addresses for consistent mapping
    private val sensorMacMap = mapOf(
        "D4:22:CD:00:7D:2D" to "LFA",
        "D4:22:CD:00:7E:FD" to "RFA",
        "D4:22:CD:00:7E:A6" to "LA",
        "D4:22:CD:00:7C:AA" to "RA",
        "D4:22:CD:00:7A:28" to "W"
    )

    private val connectedDevices = HashMap<String, DotDevice>()

    override fun configureFlutterEngine(flutterEngine: FlutterEngine) {
        super.configureFlutterEngine(flutterEngine)
        checkAndRequestPermissions()

        DotSdk.setDebugEnabled(true)
        mDotScanner = DotScanner(applicationContext, this)

        EventChannel(flutterEngine.dartExecutor.binaryMessenger, "com.example/movella_stream")
            .setStreamHandler(object : EventChannel.StreamHandler {
                override fun onListen(arguments: Any?, events: EventChannel.EventSink?) { eventSink = events }
                override fun onCancel(arguments: Any?) { eventSink = null }
            })

        MethodChannel(flutterEngine.dartExecutor.binaryMessenger, "com.example/movella_control")
            .setMethodCallHandler { call, result ->
                when (call.method) {
                    "startScan" -> { mDotScanner?.startScan(); result.success("OK") }
                    "stopScan" -> { mDotScanner?.stopScan(); result.success("OK") }
                    "connectSensor" -> {
                        // 🛡️ 強制轉大寫，保證與 SDK 回傳的格式完全一致
                        val address = call.argument<String>("address")?.uppercase()
                        if (address != null) {
                            try {
                                val bluetoothManager = getSystemService(BLUETOOTH_SERVICE) as android.bluetooth.BluetoothManager
                                val device = DotDevice(applicationContext, bluetoothManager.adapter.getRemoteDevice(address), this)
                                connectedDevices[address] = device
                                device.setDotMeasurementCallback(this)
                                device.connect()
                                result.success("OK")
                            } catch (e: Exception) {
                                result.error("CONNECT_FAIL", "連線失敗: ${e.message}", null)
                            }
                        }
                    }
                    "disconnectSensor" -> {
                        val address = call.argument<String>("address")?.uppercase()
                        if (address != null) {
                            connectedDevices[address]?.disconnect()
                            result.success("OK")
                        }
                    }
                    "startFreeMeasure" -> {
                        if (connectedDevices.isEmpty()) {
                            result.error("MEASURE_ERROR", "請至少連線 1 顆感測器", null)
                            return@setMethodCallHandler
                        }

                        Thread {
                            for (i in 0..100 step 25) {
                                runOnUiThread { eventSink?.success(hashMapOf("event" to "SYNC_PROGRESS", "progress" to i)) }
                                Thread.sleep(200)
                            }

                            for (device in connectedDevices.values) {
                                // 🛑 先強制停止
                                device.stopMeasuring()
                                Thread.sleep(150) // 🛡️ 加入 150ms 緩衝，讓藍牙消化停止指令

                                // ✅ 切換模式
                                device.measurementMode = DotPayload.PAYLOAD_TYPE_CUSTOM_MODE_5

                                // ✅ 開始測量
                                device.startMeasuring()
                                Thread.sleep(300) // 🛡️ 加入 200ms 緩衝，確保這顆感測器啟動完成才叫下一顆
                            }

                            runOnUiThread {
                                eventSink?.success(hashMapOf("event" to "SYNC_DONE", "isSynced" to true))
                            }
                        }.start()

                        result.success("已強制開啟直通模式")
                    }
                    else -> result.notImplemented()
                }
            }
    }

    override fun onDotInitDone(address: String?) {
        connectedDevices[address]?.setOutputRate(60)
    }

    override fun onDotDataChanged(address: String?, data: DotData?) {
        val d = data ?: return
        val mac = address?.uppercase() ?: return
        val sensorId = sensorMacMap[mac] ?: "W"

        // 💡 捨棄 getFreeAcc()，直接使用 getAcc() 來獲取包含重力的加速度
        val acc = d.getAcc()
        val freeAcc = d.getFreeAcc()
        val gyr = d.getGyr()
        val quat = d.getQuat()

        val singleDataMap = HashMap<String, Any?>()
        singleDataMap["event"] = "DATA"
        singleDataMap["sensorId"] = sensorId
        singleDataMap["mac"] = mac

        // We assume the Xsens SDK returns the correct length array (3 for vectors, 4 for quats).
        // Using try-catch as a final safety net to prevent any background thread crashes.
//        try {
//            // 💡 把 acc 放進 Map 傳給 Flutter
//            singleDataMap["accX"] = acc[0]
//            singleDataMap["accY"] = acc[1]
//            singleDataMap["accZ"] = acc[2]
//        } catch (e: Exception) {
//            singleDataMap["accX"] = 0.0
//            singleDataMap["accY"] = 0.0
//            singleDataMap["accZ"] = 0.0
//        }
//        try {
//            // 💡 確保傳給 Flutter 的是純粹的 FreeAcc
//            singleDataMap["accX"] = freeAcc[0]
//            singleDataMap["accY"] = freeAcc[1]
//            singleDataMap["accZ"] = freeAcc[2]
//        } catch (e: Exception) {
//            singleDataMap["accX"] = 0.0
//            singleDataMap["accY"] = 0.0
//            singleDataMap["accZ"] = 0.0
//        }
//        try {
//            singleDataMap["gyrX"] = gyr[0]
//            singleDataMap["gyrY"] = gyr[1]
//            singleDataMap["gyrZ"] = gyr[2]
//        } catch (e: Exception) {
//            singleDataMap["gyrX"] = 0.0
//            singleDataMap["gyrY"] = 0.0
//            singleDataMap["gyrZ"] = 0.0
//        }
//
//        try {
//            singleDataMap["quatW"] = quat[0].toDouble()
//            singleDataMap["quatX"] = quat[1].toDouble()
//            singleDataMap["quatY"] = quat[2].toDouble()
//            singleDataMap["quatZ"] = quat[3].toDouble()
//        } catch (e: Exception) {
//            singleDataMap["quatW"] = 1.0
//            singleDataMap["quatX"] = 0.0
//            singleDataMap["quatY"] = 0.0
//            singleDataMap["quatZ"] = 0.0
//        }
        // 🌟 1. 處理加速度
        if (acc != null && acc.size >= 3) {
            singleDataMap["accX"] = acc[0].toDouble()
            singleDataMap["accY"] = acc[1].toDouble()
            singleDataMap["accZ"] = acc[2].toDouble()
        } else if (freeAcc != null && freeAcc.size >= 3) {
            singleDataMap["accX"] = freeAcc[0].toDouble()
            singleDataMap["accY"] = freeAcc[1].toDouble()
            singleDataMap["accZ"] = freeAcc[2].toDouble()
        } else {
            // 💡 加上這行 Log，如果 Payload 設錯，Logcat 會狂刷這條訊息
            Log.w("XsensData", "[$mac] 加速度資料為空！已自動補 0。請檢查 Payload 設定或藍牙連線。")
            singleDataMap["accX"] = 0.0
            singleDataMap["accY"] = 0.0
            singleDataMap["accZ"] = 0.0
        }

// 🌟 2. 處理陀螺儀
        if (gyr != null && gyr.size >= 3) {
            singleDataMap["gyrX"] = gyr[0].toDouble()
            singleDataMap["gyrY"] = gyr[1].toDouble()
            singleDataMap["gyrZ"] = gyr[2].toDouble()
        } else {
            Log.w("XsensData", "[$mac] 陀螺儀資料為空！已自動補 0。")
            singleDataMap["gyrX"] = 0.0
            singleDataMap["gyrY"] = 0.0
            singleDataMap["gyrZ"] = 0.0
        }

// 🌟 3. 處理四元數
        if (quat != null && quat.size >= 4) {
            singleDataMap["quatW"] = quat[0].toDouble()
            singleDataMap["quatX"] = quat[1].toDouble()
            singleDataMap["quatY"] = quat[2].toDouble()
            singleDataMap["quatZ"] = quat[3].toDouble()
        } else {
            Log.w("XsensData", "[$mac] 四元數資料為空！已自動還原為單位四元數。")
            singleDataMap["quatW"] = 1.0
            singleDataMap["quatX"] = 0.0
            singleDataMap["quatY"] = 0.0
            singleDataMap["quatZ"] = 0.0
        }
        runOnUiThread { eventSink?.success(singleDataMap) }
    }

    override fun onDotScanned(device: BluetoothDevice?, rssi: Int) {
        device?.let {
            val mac = it.address.uppercase()
            if (sensorMacMap.containsKey(mac)) {
                runOnUiThread { eventSink?.success(hashMapOf("event" to "DEVICE_FOUND", "mac" to mac)) }
            }
        }
    }

    private fun checkAndRequestPermissions() {
        val permissions = mutableListOf(android.Manifest.permission.ACCESS_FINE_LOCATION)
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            permissions.add(android.Manifest.permission.BLUETOOTH_SCAN)
            permissions.add(android.Manifest.permission.BLUETOOTH_CONNECT)
        }
        val missing = permissions.filter { checkSelfPermission(it) != PackageManager.PERMISSION_GRANTED }
        if (missing.isNotEmpty()) requestPermissions(missing.toTypedArray(), 100)
    }

    override fun onDestroy() {
        super.onDestroy()
        for (device in connectedDevices.values) device.disconnect()
        connectedDevices.clear()
        mDotScanner?.stopScan()
    }

    // --- Required empty implementations ---
    override fun onDotConnectionChanged(address: String?, state: Int) {}
    override fun onSyncingStarted(address: String?, isSuccess: Boolean, requestCode: Int) {}
    override fun onSyncingProgress(progress: Int, requestCode: Int) {}
    override fun onSyncingResult(address: String?, isSuccess: Boolean, requestCode: Int) {}
    override fun onSyncingStopped(address: String?, isSuccess: Boolean, requestCode: Int) {}
    override fun onSyncingDone(syncingResultMap: HashMap<String, Boolean>, isSuccess: Boolean, requestCode: Int) {}
    override fun onDotOutputRateUpdate(address: String?, outputRate: Int) {}
    override fun onDotBatteryChanged(address: String?, status: Int, percentage: Int) {}
    override fun onDotButtonClicked(address: String?, timestamp: Long) {}
    override fun onDotButtonDoubleClicked(address: String?, timestamp: Long) {}
    override fun onDotButtonTripleClicked(address: String?, timestamp: Long) {}
    override fun onDotPowerSavingTriggered(address: String?) {}
    override fun onDotServicesDiscovered(address: String?, status: Int) {}
    override fun onDotTagChanged(address: String?, tag: String?) {}
    override fun onReadRemoteRssi(address: String?, rssi: Int) {}
    override fun onSyncStatusUpdate(address: String?, isSynced: Boolean) {}
    override fun onDotFilterProfileUpdate(address: String?, filterProfileIndex: Int) {}
    override fun onDotFirmwareVersionRead(address: String?, version: String?) {}
    override fun onDotGetFilterProfileInfo(address: String, filterProfileInfoList: ArrayList<FilterProfileInfo>) {}
    override fun onDotRotLocalRead(address: String?, quaternions: FloatArray?) {}
    override fun onDotHeadingChanged(address: String?, status: Int, result: Int) {}
}