# 智慧上肢檢測系統 (Smart Upper Limb Detection System)

本專案旨在開發一套專為「五十肩（肩關節囊游離術）」設計的跨平台行動端動作評估系統。透過穿戴式感測器與機器學習模型，提供臨床人員與受測者最直觀、客觀且精確的關節活動度（ROM）分析數據。

## 核心功能特色

* **五節點感測器佈建**：支援左/右前臂、左/右上臂及腰部共 5 個感測點，全方位捕捉上肢運動軌跡。
* **雙軌數據輸入模式**：
    * **即時錄製分析**：透過藍牙即時連線 Xsens 感測器，進行動態波形監控與數據採集。
    * **CSV 歷史匯入**：支援匯入既有的數據檔案，直接執行運動特徵辨識與模型分析。
* **專業級臨床報告**：
    * **視覺化活動度對比**：利用長條圖同步量化左、右肢體數據，精準呈現雙側活動差異。
    * **微觀動作解析**：詳盡紀錄每一 Rep 動作的「起始角度」、「終點角度」及「角度變化幅度（ROM）」。
* **長期追蹤與進度管理**：
    * **單項動作趨勢圖**：選定特定動作查看長期角度變化趨勢，支援點擊節點顯示即時數值。
    * **智能歷史檢索**：導入年、月份手動篩選功能，方便從大量歷史數據中精準定位特定紀錄。
* **高精準度 ML 分析模型**：整合隨機森林（Random Forest）等演算法，自動辨識動作類別與代償行為。

## 檢測動作清單

系統針對五十肩復健需求，完整涵蓋以下七項標準檢測動作：
1.  **前平舉** 
2.  **側平舉**
3.  **後平舉** 
4.  **水平外展** 
5.  **水平內收** 
6.  **前向肩輪**  - 包含順、逆時針分析
7.  **側向肩輪**  - 包含順、逆時針分析

## 開發技術棧

* **前端框架**：Flutter (Dart) - 支援 Android / iOS 雙平台 
* **開發環境**：Android Studio
* **感測技術**：Xsens DOT SDK & 慣性感測器 
* **數據分析**：Matlab 模型移植與即時特徵工程分析

## 操作流程

1.  **使用者登入**：進入系統進行身分驗證。
2.  **設備連線**：確認 5 顆感測器連線狀態。
3.  **檢測設定**：自訂或選定 7 項檢測動作與次數目標。
4.  **歸零校正**：執行 Heading Reset 確保基準點重置。
5.  **動作錄製**：執行檢測動作並即時監控波形。
6.  **AI 分析**：產生完整角度分析報告並儲存。
7.  **紀錄追蹤**：於歷史頁面檢視長期康復趨勢。


classDiagram
    %% 定義模組與套件
    namespace Flutter_Frontend {
        class AuthManager
        class ProfileManager
        class SensorController
        class RecordController
        class HistoryManager
        class ReportManager
    }

    namespace Native_C_Plus_Plus {
        class NativeMLBridge
        class FeatureExtractor
        class ModelLayer1
        class ModelLayer2
    }

    namespace External_SDK {
        class MovellaDotSDK
    }

    namespace Data_Models {
        class UserProfile
        class SensorData
        class AssessmentReport
    }

    %% 前端邏輯類別
    class AuthManager {
        +bool isLoginMode
        +bool isGuestMode
        +login(email, password)
        +guestLogin()
        +switchMode()
    }

    class ProfileManager {
        +saveChanges()
        +validateForm()
    }

    class SensorController {
        +List sensors
        +bool isSynced
        +connectSensors()
        +handleOneKeySync()
        +disconnect()
    }

    class RecordController {
        +RecordState currentState
        +calibrate()
        +startRecording()
        +stopRecording()
        +exportCSV()
    }

    class ReportManager {
        +generateReport()
        +buildDetailedExerciseCard()
        +checkInsufficientReps()
    }

    class HistoryManager {
        +List historyRecords
        +filterRecords(year, month)
        +loadMoreData()
        +onListScroll()
    }

    %% 原生橋接與演算法類別
    class NativeMLBridge {
        +reset_l1()
        +run_l1(input)
        +reset_l2()
        +run_l2(input)
    }

    class FeatureExtractor {
        +FFTImplementation()
        +calculateMean()
        +calculateMinOrMax()
        +calculateAbs()
        +calculateSum()
    }

    class ModelLayer1 {
        +CompactClassificationEnsemble()
        +CompactClassificationTree()
        +genc(input)
    }

    class ModelLayer2 {
        +genc2(input)
    }

    %% 外部 SDK
    class MovellaDotSDK {
        +setDebugEnabled()
        +initSDK()
        +getSensorData()
    }

    %% 資料實體
    class UserProfile {
        +String name
        +String gender
        +Date dateOfBirth
        +double height
        +double weight
        +String affectedSide
        +String medicalHistory
    }

    class SensorData {
        +double[] acceleration
        +double[] gyroscope
        +long timestamp
    }

    class AssessmentReport {
        +Date testDate
        +Time duration
        +List leftArmAngles
        +List rightArmAngles
        +int repetitions
        +bool isInsufficient
    }

    %% 定義關聯性 (Relationships)
    AuthManager --> UserProfile : Creates
    ProfileManager --> UserProfile : Manages
    HistoryManager --> AssessmentReport : Retrieves
    ReportManager --> AssessmentReport : Generates
    
    SensorController --> MovellaDotSDK : Uses
    SensorController --> SensorData : Collects
    RecordController --> SensorController : Controls
    
    RecordController --> NativeMLBridge : Sends SensorData
    NativeMLBridge --> FeatureExtractor : Calls
    NativeMLBridge --> ModelLayer1 : Calls genc()
    NativeMLBridge --> ModelLayer2 : Calls genc2()
    
    FeatureExtractor --> ModelLayer1 : Feeds Features
    FeatureExtractor --> ModelLayer2 : Feeds Features
    
    ModelLayer1 --> ReportManager : Returns Action Class
    ModelLayer2 --> ReportManager : Returns Repetitions/Angles
