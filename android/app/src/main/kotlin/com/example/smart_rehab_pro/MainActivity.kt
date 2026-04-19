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
import com.xsens.dot.android.sdk.models.DotSyncManager

import com.xsens.dot.android.sdk.interfaces.DotDeviceCallback
import com.xsens.dot.android.sdk.interfaces.DotMeasurementCallback
import com.xsens.dot.android.sdk.interfaces.DotScannerCallback
import com.xsens.dot.android.sdk.interfaces.DotSyncCallback

import java.util.ArrayList
import java.util.HashMap

class MainActivity: FlutterActivity(),
    DotDeviceCallback,
    DotMeasurementCallback,
    DotScannerCallback,
    DotSyncCallback {

    private var eventSink: EventChannel.EventSink? = null
    private var mDotScanner: DotScanner? = null

    // 💡 1. 補回 5 顆感測器名單 (掃描與資料辨識必備)
    private val sensorMacMap = mapOf(
        "D4:22:CD:00:7D:2D" to "LFA",
        "D4:22:CD:00:7E:FD" to "RFA",
        "D4:22:CD:00:7E:A6" to "LA",
        "D4:22:CD:00:7C:AA" to "RA",
        "D4:22:CD:00:7A:28" to "W"
    )

    private val connectedDevices = HashMap<String, DotDevice>()
    private val globalFeatureMap = HashMap<String, Any?>()

    // 🔥 2. 穩定同步核心狀態
    private val readyDevices = mutableSetOf<String>()
    private var masterAddress: String? = null
    private var isAllReady = false

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
                    "startScan" -> {
                        mDotScanner?.startScan()
                        result.success("開始掃描")
                    }
                    "stopScan" -> {
                        mDotScanner?.stopScan()
                        result.success("停止掃描")
                    }
                    "connectSensor" -> {
                        val address = call.argument<String>("address")
                        if (address != null) {
                            try {
                                val bluetoothManager = getSystemService(android.content.Context.BLUETOOTH_SERVICE) as android.bluetooth.BluetoothManager
                                val device = DotDevice(applicationContext, bluetoothManager.adapter.getRemoteDevice(address), this)
                                connectedDevices[address] = device
                                device.setDotMeasurementCallback(this)
                                device.connect()
                                result.success("正在連線到 $address")
                            } catch (e: Exception) {
                                result.error("CONNECT_FAIL", "連線失敗: ${e.message}", null)
                            }
                        }
                    }
                    "disconnectSensor" -> {
                        val address = call.argument<String>("address")
                        if (address != null) {
                            connectedDevices[address]?.disconnect()
                            result.success("已送出斷線指令")
                        }
                    }
                    "startSync" -> {
                        if (connectedDevices.size != 5) {
                            result.error("SYNC_ERROR", "必須連線 5 顆感測器", null)
                            return@setMethodCallHandler
                        }

                        if (!isAllReady) {
                            result.error("SYNC_ERROR", "裝置尚未準備完成 (Ready < 5)", null)
                            return@setMethodCallHandler
                        }

                        val syncManager = DotSyncManager.getInstance(this@MainActivity)

                        // ❌ 刪除這行：盲目呼叫 stopSyncing 會干擾底層狀態機
                        // syncManager.stopSyncing()

                        val deviceList = ArrayList(connectedDevices.values)
                        val master = connectedDevices[masterAddress]

                        if (master == null) {
                            result.error("SYNC_ERROR", "未找到 Master 節點", null)
                            return@setMethodCallHandler
                        }

                        // 將 Master 移動到陣列第一位 (Root 節點必須在 index 0)
                        deviceList.remove(master)
                        deviceList.add(0, master)

                        // 💡 將藍牙指令全數移入背景執行緒，避免阻塞 Flutter UI，並加入微小間隔
                        Thread {
                            Log.d("MovellaTest", "🛑 1. 強制所有感測器停止測量 (含防塞車緩衝)...")
                            for (d in deviceList) {
                                d.stopMeasuring()
                                Thread.sleep(100) // 💡 關鍵修復：給每顆感測器 100ms 的反應時間，避免藍牙指令瞬間塞爆
                            }

                            Log.d("MovellaTest", "⏳ 2. 等待 1.5 秒讓藍牙指令徹底消化...")
                            Thread.sleep(1500)

                            runOnUiThread {
                                Log.d("MovellaTest", "🚀 3. 通道已淨空，正式啟動同步，Master: ${master.address}")
                                syncManager.startSyncing(deviceList, 0)
                                result.success("同步指令已送出")
                            }
                        }.start()
                    }
                    else -> result.notImplemented()
                }
            }
    }

    override fun onDestroy() {
        super.onDestroy()
        for (device in connectedDevices.values) { device.disconnect() }
        connectedDevices.clear()
        mDotScanner?.stopScan()
    }

    private fun checkAndRequestPermissions() {
        val permissionsNeeded = mutableListOf(android.Manifest.permission.ACCESS_FINE_LOCATION, android.Manifest.permission.ACCESS_COARSE_LOCATION)
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            permissionsNeeded.add(android.Manifest.permission.BLUETOOTH_SCAN)
            permissionsNeeded.add(android.Manifest.permission.BLUETOOTH_CONNECT)
        }
        val missingPermissions = permissionsNeeded.filter { checkSelfPermission(it) != PackageManager.PERMISSION_GRANTED }
        if (missingPermissions.isNotEmpty()) requestPermissions(missingPermissions.toTypedArray(), 100)
    }

    private fun sendToFlutter(data: HashMap<String, Any?>) {
        runOnUiThread { eventSink?.success(data) }
    }

    // ==========================================
    // 💡 3. 補回掃描回呼 (畫面才能出現卡片)
    // ==========================================
    override fun onDotScanned(device: BluetoothDevice?, rssi: Int) {
        device?.let {
            if (sensorMacMap.containsKey(it.address)) {
                runOnUiThread {
                    eventSink?.success(hashMapOf("event" to "DEVICE_FOUND", "mac" to it.address))
                }
            }
        }
    }

    override fun onDotConnectionChanged(address: String?, state: Int) {
        if (state == 2 && address != null) {
            Log.d("MovellaTest", "⚡ $address 牽手成功，等待暖機...")
        } else if (state == 0) {
            Log.d("MovellaTest", "❌ $address 斷線了")
            connectedDevices.remove(address)
            readyDevices.remove(address)
            if (masterAddress == address) masterAddress = null
            isAllReady = false
        }
    }

    override fun onDotInitDone(address: String?) {
        if (address == null) return
        val device = connectedDevices[address] ?: return

        Log.d("MovellaTest", "⚙️ $address Init完成，執行 Trick 強制寫入...")

        // 🔥 強制裝置進入一致狀態 (你找出的 Trick)
        device.stopMeasuring()
        device.setOutputRate(60)

        // 啟動再關閉，迫使硬體內部參數生效
        Thread {
            device.startMeasuring()
            Thread.sleep(300)
            device.stopMeasuring()
            Log.d("MovellaTest", "⚙️ $address Trick 執行完畢，等待 60Hz 回報...")
        }.start()
    }

    override fun onDotOutputRateUpdate(address: String?, outputRate: Int) {
        if (address == null) return

        if (outputRate == 60) {
            Log.d("MovellaTest", "✅ $address 回報 Ready (60Hz)!")
            readyDevices.add(address)

            if (masterAddress == null) {
                masterAddress = address
                Log.d("MovellaTest", "👑 指派 Master = $address")
            }

            if (readyDevices.size == 5) {
                isAllReady = true
                Log.d("MovellaTest", "🎯🎯🎯 全部 5 顆裝置已 Ready！可以執行同步！")
            }
        }
    }

    override fun onSyncingStarted(address: String?, isSuccess: Boolean, requestCode: Int) {}

    override fun onSyncingProgress(progress: Int, requestCode: Int) {
        Log.d("MovellaTest", "⏳ 同步進度: $progress%")
        runOnUiThread { eventSink?.success(hashMapOf("event" to "SYNC_PROGRESS", "progress" to progress)) }
    }

    override fun onSyncingResult(address: String?, isSuccess: Boolean, requestCode: Int) {
        Log.d("MovellaTest", "-> 🔍 $address 單顆同步: ${if(isSuccess) "✅" else "❌"}")
    }

    override fun onSyncingStopped(address: String?, isSuccess: Boolean, requestCode: Int) {}

    override fun onSyncingDone(syncingResultMap: HashMap<String, Boolean>, isSuccess: Boolean, requestCode: Int) {
        Log.d("MovellaTest", "🎉 官方硬體同步結果出爐！ 整體成功: $isSuccess")

        if (isSuccess) {
            for (device in connectedDevices.values) {
                device.measurementMode = DotPayload.PAYLOAD_TYPE_EXTENDED_QUATERNION
                device.startMeasuring()
                Log.d("MovellaTest", "🌊 ${device.address} 資料流已開啟！")
            }
        }

        runOnUiThread { eventSink?.success(hashMapOf("event" to "SYNC_DONE", "isSynced" to isSuccess)) }
    }

    // ==========================================
    // 💡 4. 修復波浪圖資料傳輸，加上前綴與重力扣除
    // ==========================================
    override fun onDotDataChanged(address: String?, data: DotData?) {
        // 裝監視器：硬體真的有吐資料給手機嗎？
        Log.d("MovellaData", "📡 硬體吐資料了！ 來自: $address")
        val d = data ?: return
        val mac = address ?: return
        val sensorId = sensorMacMap[mac] ?: return

        val acc = d.getAcc()
        val gyr = d.getGyr()
        val quat = d.getQuat()

        // 必須加上 sensorId (如 LFA_accX)，否則 5 顆資料會互相覆蓋！
        globalFeatureMap["${sensorId}_accX"] = acc[0]
        globalFeatureMap["${sensorId}_accY"] = acc[1]
        globalFeatureMap["${sensorId}_accZ"] = acc[2]

        globalFeatureMap["${sensorId}_gyrX"] = gyr[0]
        globalFeatureMap["${sensorId}_gyrY"] = gyr[1]
        globalFeatureMap["${sensorId}_gyrZ"] = gyr[2]

        globalFeatureMap["${sensorId}_quatW"] = quat[0]
        globalFeatureMap["${sensorId}_quatX"] = quat[1]
        globalFeatureMap["${sensorId}_quatY"] = quat[2]
        globalFeatureMap["${sensorId}_quatZ"] = quat[3]

        // 算出 3D 加速度，扣掉重力 9.81 (給前端波浪圖用的核心數據)
        val accMag = Math.sqrt((acc[0]*acc[0] + acc[1]*acc[1] + acc[2]*acc[2]).toDouble())
        globalFeatureMap["${sensorId}_accMagXY"] = Math.abs(accMag - 9.81)

        // 標記這是數據流
        globalFeatureMap["event"] = "DATA"
        sendToFlutter(HashMap(globalFeatureMap))
    }

    // 其他閒置回呼
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