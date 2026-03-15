#include "model_layer2/genc2.h"
#include "model_layer2/genc2_initialize.h"

extern "C" {
__attribute__((visibility("default"))) __attribute__((used))
void reset_l2() {
    layer2::genc2_initialize();
}

__attribute__((visibility("default"))) __attribute__((used))
double run_l2(double* input) {
    return layer2::genc2(input);
}
}