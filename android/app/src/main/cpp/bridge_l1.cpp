#include "model_layer1/genc.h"
#include "model_layer1/genc_initialize.h" // 🌟 1. 引入初始化標頭檔
#include "model_layer1/coder_array.h"

// 🌟 2. 用 extern "C" 把所有要給 Flutter 呼叫的函數包起來
extern "C" {

// 🌟 3. 新增這個函數，用來重置 MATLAB 模型的內部狀態
__attribute__((visibility("default"))) __attribute__((used))
void reset_l1() {
    // 呼叫 MATLAB 生成的初始化函數，清空所有暫存的時間視窗與濾波器狀態
    layer1::genc_initialize();
}

__attribute__((visibility("default"))) __attribute__((used))
double run_l1(double* input) {
    coder::array<double, 2U> in;
    in.set_size(1, 280);
    for(int i=0; i<280; i++) in[i] = input[i];

    coder::array<double, 1U> out;

    // 執行推論
    layer1::genc(in, out);

    return (out.size(0) > 0) ? out[0] : 0.0;
}

} // extern "C" 結束