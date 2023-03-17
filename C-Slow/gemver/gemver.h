typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 256

void gemver(inout_float_t A[65536], in_float_t u1[256], in_float_t v1[256],
            in_float_t u2[256], in_float_t v2[256], inout_float_t w[256],
            inout_float_t x[256], in_float_t y[256], in_float_t z[256]);
