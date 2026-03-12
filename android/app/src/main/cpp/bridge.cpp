#include "model_layer1/genc.h"
#include "model_layer2/genc2.h"
#include "model_layer1/coder_array.h"
#include <stdint.h>

extern "C" {
__attribute__((visibility("default"))) __attribute__((used))
double run_hierarchical_model(double* input_280) {
    // --- 第一層辨識 ---
    coder::array<double, 2U> matlab_input;
    matlab_input.set_size(1, 280);
    for (int i = 0; i < 280; i++) {
        matlab_input[i] = input_280[i];
    }

    coder::array<double, 1U> l1_output;
    genc(matlab_input, l1_output);

    double l1_label = (l1_output.size(0) > 0) ? l1_output[0] : 0.0;

    // --- 條件判斷邏輯 ---
    // 只有當第一層標籤為 1 時，才執行第二層辨識
    if (l1_label == 1.0) {
        coder::array<double, 1U> l2_output;
        genc2(matlab_input, l2_output);

        return (l2_output.size(0) > 0) ? l2_output[0] : -1.0;
    } else {
        // 如果第一層不是 1，則回傳 0 或其他代表「未進入第二層」的數值
        return 0.0;
    }
}
}