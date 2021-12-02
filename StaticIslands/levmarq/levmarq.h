typedef int in_int_t;
typedef int out_int_t;
typedef int inout_int_t;
typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 1024
#define M 3

void levmarq(in_int_t ny, in_float_t dysq[N], in_float_t y[N], in_int_t npar,
             inout_float_t g[M], inout_float_t d[M], inout_float_t h[M][M]);
