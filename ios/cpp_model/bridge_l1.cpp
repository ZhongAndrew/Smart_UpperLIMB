#include "model_layer1/genc.h"
#include "model_layer1/genc_initialize.h"

extern "C" {
__attribute__((visibility("default"))) __attribute__((used))
void reset_l1() {
    layer1::genc_initialize();
}

__attribute__((visibility("default"))) __attribute__((used))
double run_l1(double* input) {
    return layer1::genc(input);
}
}