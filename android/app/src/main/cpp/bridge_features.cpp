//
// Created by chen on 2026/3/30.
//
#include <stdint.h>
// 引入剛剛生成的特徵擷取標頭檔 (路徑對齊你剛剛建的資料夾)
#include "feature_extractor/extract_features.h"

extern "C" {

// 暴露給 Dart 呼叫的函數
__attribute__((visibility("default"))) __attribute__((used))
void run_extract_features(double* window_data, double* output_features) {

    // 呼叫 MATLAB 產生的 C++ 函數
    feature_exraction::extract_features(window_data, output_features);
}

}