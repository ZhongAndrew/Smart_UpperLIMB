#include "model_layer2/genc2.h"
#include "model_layer2/coder_array.h"

extern "C" __attribute__((visibility("default"))) __attribute__((used))
double run_l2(double* input) {
    coder::array<double, 2U> in;
    in.set_size(1, 280);
    for(int i=0; i<280; i++) in[i] = input[i];

    coder::array<double, 1U> out;

    // 💡 修正這裡：加上 layer2::
    layer2::genc2(in, out);

    return (out.size(0) > 0) ? out[0] : 0.0;
}