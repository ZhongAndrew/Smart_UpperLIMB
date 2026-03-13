#include "model_layer2/genc2.h"
#include "model_layer2/genc2_initialize.h" // 🌟 1. 引入第二層的初始化標頭檔
#include "model_layer2/coder_array.h"

extern "C" {
// 🌟 2. 新增第二層的重置函數
__attribute__((visibility("default"))) __attribute__((used))
void reset_l2() {
    layer2::genc2_initialize(); // 呼叫 MATLAB 生成的第二層清空函數
}

__attribute__((visibility("default"))) __attribute__((used))
double run_l2(double* input) {
    coder::array<double, 2U> in;
    in.set_size(1, 280);
    for(int i=0; i<280; i++) in[i] = input[i];

    coder::array<double, 1U> out;

    layer2::genc2(in, out);

    return (out.size(0) > 0) ? out[0] : 0.0;
}
}