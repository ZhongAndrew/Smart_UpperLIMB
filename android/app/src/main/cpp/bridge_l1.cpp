#include "model_layer1/genc.h"
#include "model_layer1/coder_array.h"

extern "C" __attribute__((visibility("default"))) __attribute__((used))
double run_l1(double* input) {
    coder::array<double, 2U> in;
    in.set_size(1, 280);
    for(int i=0; i<280; i++) in[i] = input[i];

    coder::array<double, 1U> out;

    // 💡 修正這裡：加上 layer1::
    layer1::genc(in, out);

    return (out.size(0) > 0) ? out[0] : 0.0;
}