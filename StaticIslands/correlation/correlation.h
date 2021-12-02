typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 32

void correlation(inout_float_t m[N], inout_float_t s[N],
                 inout_float_t data[N][N], inout_float_t corr[N][N]);
