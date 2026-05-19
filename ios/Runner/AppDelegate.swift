import UIKit
import Flutter
import MovellaDotSdk // 確保這裡是你的 Framework 名稱

@main
@objc class AppDelegate: FlutterAppDelegate, FlutterStreamHandler, DotConnectionDelegate {

    private var eventSink: FlutterEventSink?

    // iOS 無法直接用 MAC 連線，必須從掃描結果中抓取物件
    private var scannedDevices = [String: DotDevice]()
    private var connectedDevices = [String: DotDevice]()

    // 感測器位置對應表 (強制轉大寫比對)
    private let sensorMacMap: [String: String] = [
        "D4:22:CD:00:7D:2D": "LFA",
        "D4:22:CD:00:7E:FD": "RFA",
        "D4:22:CD:00:7E:A6": "LA",
        "D4:22:CD:00:7C:AA": "RA",
        "D4:22:CD:00:7A:28": "W"
    ]

    override func application(
        _ application: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?
    ) -> Bool {

        // 🚨 1. 設定 Movella 連線管理員的 Delegate
        DotConnectionManager.setConnectionDelegate(self)

        // 🚨 2. 安全地取得 FlutterViewController 並註冊通道 (使用非同步避免 nil 崩潰)
        DispatchQueue.main.async {
            var flutterVC: FlutterViewController?

            // 嘗試取得畫面 (相容 AppDelegate 架構)
            if let rootVC = self.window?.rootViewController as? FlutterViewController {
                flutterVC = rootVC
            }
            // 嘗試取得畫面 (相容較新的 SceneDelegate 架構)
            else {
                if #available(iOS 13.0, *) {
                    if let windowScene = UIApplication.shared.connectedScenes.first as? UIWindowScene,
                       let rootVC = windowScene.windows.first?.rootViewController as? FlutterViewController {
                        flutterVC = rootVC
                    }
                }
            }

            // 只要成功抓到畫面，就立刻綁定 Dart/Swift 通訊管道
            if let controller = flutterVC {
                let eventChannel = FlutterEventChannel(name: "com.example/movella_stream", binaryMessenger: controller.binaryMessenger)
                eventChannel.setStreamHandler(self)

                let methodChannel = FlutterMethodChannel(name: "com.example/movella_control", binaryMessenger: controller.binaryMessenger)
                methodChannel.setMethodCallHandler { [weak self] (call: FlutterMethodCall, result: @escaping FlutterResult) in
                    self?.handleMethodCall(call: call, result: result)
                }
            } else {
                print("⚠️ 無法找到 FlutterViewController，請確認專案架構")
            }
        }

        GeneratedPluginRegistrant.register(with: self)
        return super.application(application, didFinishLaunchingWithOptions: launchOptions)
    }

    // MARK: - MethodChannel 邏輯處理
    private func handleMethodCall(call: FlutterMethodCall, result: @escaping FlutterResult) {
        let args = call.arguments as? [String: Any]
        let macAddress = (args?["address"] as? String)?.uppercased()

        switch call.method {
        case "startScan":
            scannedDevices.removeAll()
            DotConnectionManager.scan() // 🚨 靜態呼叫掃描
            result("OK")

        case "stopScan":
            DotConnectionManager.stopScan()
            result("OK")

        case "connectSensor":
            guard let mac = macAddress, let device = scannedDevices[mac] else {
                result(FlutterError(code: "CONNECT_FAIL", message: "連線失敗: 在 iOS 必須先掃描到感測器才能連線", details: nil))
                return
            }
            DotConnectionManager.connect(device)
            result("OK")

        case "disconnectSensor":
            guard let mac = macAddress, let device = connectedDevices[mac] else {
                result("OK")
                return
            }
            DotConnectionManager.disconnect(device)
            result("OK")

        case "prepareSensors":
            if connectedDevices.isEmpty {
                result(FlutterError(code: "ERROR", message: "請至少連線 1 顆感測器", details: nil))
                return
            }

            DispatchQueue.global(qos: .userInitiated).async {
                print("MovellaSync: 階段 1 - 清除舊有同步狀態")
                let devicesToStop = Array(self.connectedDevices.values)
                DotSyncManager.stopSync(devicesToStop)

                Thread.sleep(forTimeInterval: 1.5)

                print("MovellaSync: 階段 2 - 確保停止測量並設定 Payload Mode")
                for device in self.connectedDevices.values {
                    device.plotMeasureEnable = false
                    Thread.sleep(forTimeInterval: 0.2)

                    device.plotMeasureMode = .customMode5 // 🚨 屬性改名
                    Thread.sleep(forTimeInterval: 0.2)
                }

                print("MovellaSync: 準備完成")
                DispatchQueue.main.async { result("準備完成") }
            }

        case "startHardwareSync":
            if connectedDevices.count < 2 {
                result(FlutterError(code: "SYNC_ERROR", message: "同步至少需要 2 顆感測器連線", details: nil))
                return
            }

            DispatchQueue.main.async {
                print("MovellaSync: 準備同步，裝置數量: \(self.connectedDevices.count)")

                let rootMac = self.sensorMacMap.first { $0.value == "N" }?.key
                let rootDevice = rootMac != nil ? self.connectedDevices[rootMac!] : nil

                var deviceList = [DotDevice]()
                if let root = rootDevice {
                    deviceList.append(root)
                    let others = self.connectedDevices.values.filter { $0.macAddress != rootMac }.sorted { $0.macAddress < $1.macAddress }
                    deviceList.append(contentsOf: others)
                } else {
                    deviceList = self.connectedDevices.values.sorted { $0.macAddress < $1.macAddress }
                }

                self.eventSink?(["event": "SYNC_STATUS", "status": "STARTED"])

                // 🚨 處理同步閉包
                let isSupported = DotSyncManager.startSync(deviceList) { [weak self] (syncResults: [Any]) in
                    guard let self = self else { return }

                    var allSuccess = true
                    var failedSensors: [String] = []

                    for resultItem in syncResults {
                        if let dict = resultItem as? [String: Any],
                           let address = dict["address"] as? String,
                           let successFlag = dict["success"] as? Int {

                            if successFlag == 0 {
                                allSuccess = false
                                let sensorId = self.sensorMacMap[address.uppercased()] ?? address
                                failedSensors.append(sensorId)
                            }
                        }
                    }

                    if allSuccess {
                        print("MovellaSync: 同步完美成功！準備啟動資料測量...")
                        DispatchQueue.global(qos: .userInitiated).async {
                            Thread.sleep(forTimeInterval: 2.0)
                            for device in self.connectedDevices.values {
                                device.plotMeasureEnable = true // 🚨 改用屬性啟動測量
                                Thread.sleep(forTimeInterval: 0.25)
                            }
                            DispatchQueue.main.async {
                                self.eventSink?(["event": "SYNC_DONE", "isSynced": true])
                            }
                        }
                    } else {
                        let errorMsg = failedSensors.isEmpty ? "同步超時或不明錯誤" : "同步失敗！問題感測器：\(failedSensors.joined(separator: ", "))"
                        print("MovellaSync: \(errorMsg)")
                        DispatchQueue.main.async {
                            self.eventSink?(["event": "SYNC_DONE", "isSynced": false, "error": errorMsg])
                        }
                    }
                }

                if isSupported {
                    result("同步指令已發射")
                } else {
                    result(FlutterError(code: "SYNC_FAIL", message: "硬體不支援同步功能", details: nil))
                }
            }

        case "startFreeMeasure":
        for device in connectedDevices.values {
            // 💡 配合 Dart 的模擬同步：在啟動測量前，直接強制設定為你要的格式
            device.plotMeasureMode = .customMode5

            // 給藍牙一點反應時間切換模式 (很重要，否則可能會掉包)
            Thread.sleep(forTimeInterval: 0.1)

            // 啟動資料流
            device.plotMeasureEnable = true
        }
        result("直通模式已啟動")

        case "stopFreeMeasure":
            for device in connectedDevices.values {
                device.plotMeasureEnable = false
            }
            result("測量已停止")

        default:
            result(FlutterMethodNotImplemented)
        }
    }

    // MARK: - FlutterStreamHandler
    func onListen(withArguments arguments: Any?, eventSink events: @escaping FlutterEventSink) -> FlutterError? {
        self.eventSink = events
        return nil
    }

    func onCancel(withArguments arguments: Any?) -> FlutterError? {
        self.eventSink = nil
        return nil
    }

    // MARK: - DotConnectionDelegate 實作
    func onDiscover(_ device: DotDevice) {
        let mac = device.macAddress.uppercased()
        scannedDevices[mac] = device

        if sensorMacMap.keys.contains(mac) {
            DispatchQueue.main.async {
                self.eventSink?(["event": "DEVICE_FOUND", "mac": mac])
            }
        }
    }

    func onDeviceConnectSucceeded(_ device: DotDevice) {
        let mac = device.macAddress.uppercased()
        connectedDevices[mac] = device

        // 設定專案要求的採樣頻率 (64Hz)
        device.outputRate = 64

        // 🚨 直接在這裡綁定資料接收的閉包！
        device.setDidParsePlotDataBlock { [weak self] (data: DotPlotData) in
            guard let self = self else { return }

            let sensorId = self.sensorMacMap[mac] ?? "W"

            var singleDataMap: [String: Any] = [
                "event": "DATA",
                "sensorId": sensorId,
                "mac": mac,
                "timestamp": data.timeStamp // 🚨 攤平後的時間變數
            ]

            // 🚨 攤平後的感測器資料變數
            // 加速度
            singleDataMap["accX"] = data.acc0
            singleDataMap["accY"] = data.acc1
            singleDataMap["accZ"] = data.acc2

            // 陀螺儀
            singleDataMap["gyrX"] = data.gyr0
            singleDataMap["gyrY"] = data.gyr1
            singleDataMap["gyrZ"] = data.gyr2

            // 四元數
            singleDataMap["quatW"] = Double(data.quatW)
            singleDataMap["quatX"] = Double(data.quatX)
            singleDataMap["quatY"] = Double(data.quatY)
            singleDataMap["quatZ"] = Double(data.quatZ)

            DispatchQueue.main.async {
                self.eventSink?(singleDataMap)
            }
        }
    }

    func onDeviceDisconnected(_ device: DotDevice) {
        let mac = device.macAddress.uppercased()
        connectedDevices.removeValue(forKey: mac)
    }
}