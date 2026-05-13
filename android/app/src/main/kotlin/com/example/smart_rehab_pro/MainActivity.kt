package com.example.smart_rehab_pro

import android.os.Build
import android.content.pm.PackageManager
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
import com.xsens.dot.android.sdk.models.DotSyncManager

import java.util.ArrayList
import java.util.HashMap
import java.util.concurrent.ConcurrentHashMap

class MainActivity: FlutterActivity(),
    DotDeviceCallback, DotMeasurementCallback, DotScannerCallback, DotSyncCallback {

    private var eventSink: EventChannel.EventSink? = null
    private var mDotScanner: DotScanner? = null
    private var syncManager: DotSyncManager? = null

    // Force uppercase MAC addresses for consistent mapping
    private val sensorMacMap = mapOf(
        "D4:22:CD:00:7D:2D" to "LFA",
        "D4:22:CD:00:7E:FD" to "RFA",
        "D4:22:CD:00:7E:A6" to "LA",
        "D4:22:CD:00:7C:AA" to "RA",
        "D4:22:CD:00:7A:28" to "W"
    )

    // 使用 ConcurrentHashMap 提升多執行緒下操作藍牙設備的安全性
    private val connectedDevices = ConcurrentHashMap<String, DotDevice>()

    override fun configureFlutterEngine(flutterEngine: FlutterEngine) {
        super.configureFlutterEngine(flutterEngine)
        checkAndRequestPermissions()

        DotSdk.setDebugEnabled(true)
        mDotScanner = DotScanner(applicationContext, this)

        // 初始化硬體同步管理器
        syncManager = DotSyncManager.getInstance(this)

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

                    // 🚨 修改 1：優雅的準備流程，不暴力喚醒
                    "prepareSensors" -> {
                        if (connectedDevices.isEmpty()) {
                            result.error("ERROR", "請至少連線 1 顆感測器", null)
                            return@setMethodCallHandler
                        }

                        Thread {
                            Log.d("XsensSync", "prepareSensors: 階段 1 - 清除舊有同步狀態")
                            syncManager?.stopSyncing()
                            Thread.sleep(1500) // 給予 SDK 充裕時間釋放資源

                            Log.d("XsensSync", "prepareSensors: 階段 2 - 確保停止測量並設定 Payload Mode")
                            for (device in connectedDevices.values) {
                                device.stopMeasuring() // 確保完全安靜
                                Thread.sleep(200) // 給予藍牙指令緩衝，避免 GATT 塞車

                                device.measurementMode = DotPayload.PAYLOAD_TYPE_CUSTOM_MODE_5
                                Thread.sleep(200)
                            }

                            Log.d("XsensSync", "prepareSensors 完成，感測器已完全靜默並準備好參數")
                            runOnUiThread { result.success("準備完成") }
                        }.start()
                    }

                    // 🚨 修改 2：固定 Root 節點發射同步
                    "startHardwareSync" -> {
                        if (connectedDevices.size < 2) {
                            result.error("SYNC_ERROR", "同步至少需要 2 顆感測器連線", null)
                            return@setMethodCallHandler
                        }

                        runOnUiThread {
                            Log.d("XsensSync", "準備同步，裝置數量: ${connectedDevices.size}")

                            // 尋找標籤為 "W" 的感測器作為 Root，確保物理訊號最穩
                            val rootMac = sensorMacMap.entries.firstOrNull { it.value == "W" }?.key
                            val rootDevice = connectedDevices[rootMac]

                            val deviceList = ArrayList<DotDevice>()
                            if (rootDevice != null) {
                                deviceList.add(rootDevice) // Root 永遠排第一位 (index 0)
                                deviceList.addAll(connectedDevices.values.filter { it.address != rootMac }.sortedBy { it.address })
                            } else {
                                // 如果沒連上 W，再退化成預設排序
                                deviceList.addAll(connectedDevices.values.sortedBy { it.address })
                            }

                            val startSuccess = syncManager?.startSyncing(deviceList, 0) ?: false
                            Log.d("XsensSync", "startSyncing 回傳: $startSuccess")

                            if (startSuccess) {
                                result.success("同步指令已發射")
                            } else {
                                result.error("SYNC_FAIL", "SDK 拒絕執行同步", null)
                            }
                        }
                    }

                    "startFreeMeasure" -> {
                        for (device in connectedDevices.values) {
                            device.startMeasuring()
                        }
                        result.success("直通模式已啟動")
                    }
                    // 👇 加上這段：停止接收資料 👇
                    "stopFreeMeasure" -> {
                        for (device in connectedDevices.values) {
                            device.stopMeasuring()
                        }
                        result.success("測量已停止")
                    }
                    else -> result.notImplemented()
                }
            }
    }

    override fun onDotInitDone(address: String?) {
        // 設定傳輸頻率為 60Hz
        connectedDevices[address]?.setOutputRate(60)
    }

    override fun onDotDataChanged(address: String?, data: DotData?) {
        val d = data ?: return
        val mac = address?.uppercase() ?: return
        val sensorId = sensorMacMap[mac] ?: "W"

        val acc = d.getAcc()
        val freeAcc = d.getFreeAcc()
        val gyr = d.getGyr()
        val quat = d.getQuat()

        val singleDataMap = HashMap<String, Any?>()
        singleDataMap["event"] = "DATA"
        singleDataMap["sensorId"] = sensorId
        singleDataMap["mac"] = mac
        singleDataMap["timestamp"] = d.sampleTimeFine

        // 處理加速度
        if (acc != null && acc.size >= 3) {
            singleDataMap["accX"] = acc[0].toDouble()
            singleDataMap["accY"] = acc[1].toDouble()
            singleDataMap["accZ"] = acc[2].toDouble()
        } else if (freeAcc != null && freeAcc.size >= 3) {
            singleDataMap["accX"] = freeAcc[0].toDouble()
            singleDataMap["accY"] = freeAcc[1].toDouble()
            singleDataMap["accZ"] = freeAcc[2].toDouble()
        } else {
            singleDataMap["accX"] = 0.0
            singleDataMap["accY"] = 0.0
            singleDataMap["accZ"] = 0.0
        }

        // 處理陀螺儀
        if (gyr != null && gyr.size >= 3) {
            singleDataMap["gyrX"] = gyr[0].toDouble()
            singleDataMap["gyrY"] = gyr[1].toDouble()
            singleDataMap["gyrZ"] = gyr[2].toDouble()
        } else {
            singleDataMap["gyrX"] = 0.0
            singleDataMap["gyrY"] = 0.0
            singleDataMap["gyrZ"] = 0.0
        }

        // 處理四元數
        if (quat != null && quat.size >= 4) {
            singleDataMap["quatW"] = quat[0].toDouble()
            singleDataMap["quatX"] = quat[1].toDouble()
            singleDataMap["quatY"] = quat[2].toDouble()
            singleDataMap["quatZ"] = quat[3].toDouble()
        } else {
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

    // --- 🌟 真正的硬體同步 Callback 實作區塊 ---

    override fun onSyncingStarted(address: String?, isSuccess: Boolean, requestCode: Int) {
        if (isSuccess) {
            runOnUiThread {
                eventSink?.success(hashMapOf("event" to "SYNC_STATUS", "status" to "STARTED"))
            }
        }
    }

    override fun onSyncingProgress(progress: Int, requestCode: Int) {
        runOnUiThread {
            eventSink?.success(hashMapOf("event" to "SYNC_PROGRESS", "progress" to progress))
        }
    }

    // 🚨 修改 3：甦醒緩衝機制
    override fun onSyncingDone(syncingResultMap: HashMap<String, Boolean>, isSuccess: Boolean, requestCode: Int) {
        if (isSuccess) {
            Log.d("XsensSync", "同步完美成功！準備啟動資料測量...")
            Thread {
                // 🌟 核心防線：硬體對時完成後，給予剛甦醒的藍牙 2 秒鐘穩固連線
                Thread.sleep(2000)

                // 依序啟動測量，並給予間隔，避免 5 顆感測器瞬間同時噴發資料導致底層崩潰
                for (device in connectedDevices.values) {
                    device.startMeasuring()
                    Thread.sleep(250)
                }

                runOnUiThread {
                    eventSink?.success(hashMapOf("event" to "SYNC_DONE", "isSynced" to true))
                }
            }.start()
        } else {
            // 挑出失敗的感測器名稱方便 Debug
            val failedSensors = syncingResultMap.filter { !it.value }.keys.map { mac ->
                sensorMacMap[mac.uppercase()] ?: mac
            }
            val errorMsg = if (failedSensors.isNotEmpty()) "同步失敗！問題感測器：${failedSensors.joinToString()}" else "同步超時，請重啟感測器"
            Log.e("XsensSync", errorMsg)

            runOnUiThread {
                eventSink?.success(hashMapOf("event" to "SYNC_DONE", "isSynced" to false, "error" to errorMsg))
            }
        }
    }

    override fun onSyncingResult(address: String?, isSuccess: Boolean, requestCode: Int) {
        Log.d("XsensSync", "Sensor $address sync result: $isSuccess")
    }

    // 其餘留空的 Required implementations
    override fun onDotConnectionChanged(address: String?, state: Int) {}
    override fun onSyncingStopped(address: String?, isSuccess: Boolean, requestCode: Int) {}
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