#include "model_layer1/genc.h"
#include "model_layer1/genc_initialize.h"

extern "C" {
__attribute__((visibility("default"))) __attribute__((used))
void reset_l1() {
    layer1::genc_initialize();
}

__attribute__((visibility("default"))) __attribute__((used))
double run_l1(double* input) {
    // 直接將連續的 280 個數字指標餵給模型，不再透過 array 轉換！
    return layer1::genc(input);
}
}