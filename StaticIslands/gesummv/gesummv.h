typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 256

void gesummv(in_float_t A[N][N], in_float_t B[N][N], out_float_t tmp[N],
             out_float_t y[N], in_float_t x[N]);
