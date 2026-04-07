package com.example.smart_rehab_pro

import io.flutter.embedding.android.FlutterActivity
import com.xsens.dot.android.sdk.DotSdk
class MainActivity : FlutterActivity() {
    override fun configureFlutterEngine
                (flutterEngine: io.flutter.embedding.engine.FlutterEngine) {
        super.configureFlutterEngine(flutterEngine)
        // 這是啟動 Movella SDK 的偵錯模式
        com.xsens.dot.android.sdk.DotSdk.setDebugEnabled(true)
        println("成功呼叫 Movella SDK！")
    }
}
