typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 32

void syr2k(in_float_t A[N][N], in_float_t B[N][N], inout_float_t C[N][N]);
