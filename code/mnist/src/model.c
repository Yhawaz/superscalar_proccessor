
#include "model.h"
#include "weights.h"
#include "utils.h"
#include "mul.h"


#define OUTPUT_MAX 127
#define OUTPUT_MIN -128

int32_t requantize_single_rounding(const int32_t val, const int32_t multiplier, const int32_t shift) {
    const int32_t total_shift = 31 - shift - 1 - 32;

    int32_t a1 = val >> 16;
    int32_t b1 = val & 0xFFFF;

    int32_t c1 = multiplier >> 16;
    int32_t d1 = multiplier & 0xFFFF;


    int32_t ac = a1 * c1;
    int32_t ad = a1 * d1;
    int32_t bc = b1 * c1;
    
    
    int32_t result = (ac >> total_shift) + ((ad + bc) >> (total_shift + 16));
    // int32_t result = new_val >> (total_shift - 1);
    result = (result + 1) >> 1;

    return result;
}

void fully_connected(int8_t* input, const int32_t input_ch, const int8_t* filter, int8_t* output,
                     const int32_t output_ch, const int32_t input_offset, const int32_t output_offset,
                     const int32_t multiplier, const int32_t shift) {

    for(int ic = 0 ; ic < input_ch; ++ic) input[ic] += input_offset;

    int oc_offset = 0;
    for (int oc = 0; oc < output_ch; oc++) {
        int accumulator = 0;

        #pragma GCC unroll 16 
        for (int ic = 0; ic < input_ch; ic+=4) {
            accumulator += packmul(* ((int32_t*)&input[ic] ) , *(int32_t *)&filter[oc_offset]);
            oc_offset += 4;
        }
        // per-tensor quantization
        accumulator = requantize_single_rounding(accumulator, multiplier, shift);
        accumulator += output_offset;
        accumulator = accumulator > OUTPUT_MAX ? OUTPUT_MAX : accumulator;
        accumulator = accumulator < OUTPUT_MIN ? OUTPUT_MIN : accumulator;
        output[oc] = (int8_t)(accumulator);

        // print_string("ndone\n");
            // print_string("node done \n");
        // print_char('\n');
    }
}


static int8_t buffer[1100];

int8_t* getInput() { return &buffer[0]; }
int8_t* getOutput() { return &buffer[100]; }

void inference() {
    fully_connected(&buffer[0], 784, weight0, &buffer[784], 300, 128, -128, 1714425232, -10);
    print_string("layer one done\n");
    fully_connected(&buffer[784], 300, weight1, &buffer[0], 100, 128, -128, 1490186346, -8);
    print_string("layer two done\n");
    fully_connected(&buffer[0], 100, weight2, &buffer[100], 10, 128, 21, 1349101615, -9);
    print_string("layer three done\n");
}

void wrong_inference() {
    // only perform 2 last layer (for finishing the simulation in time)
    for(int i = 0; i < 300; i++) {
        buffer[i + 784] = buffer[i];
    }
    fully_connected(&buffer[784], 300, weight1, &buffer[0], 100, 128, -128, 1490186346, -8);
    fully_connected(&buffer[0], 100, weight2, &buffer[100], 10, 128, 21, 1349101615, -9);
}