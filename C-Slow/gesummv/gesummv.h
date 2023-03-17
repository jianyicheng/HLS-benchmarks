typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 256

void gesummv(in_float_t A[65536], in_float_t B[65536], out_float_t tmp[256],
             out_float_t y[256], in_float_t x[256]);
