typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 256

void doitgenTriple(inout_float_t A[N], in_float_t w[N][N],
                   inout_float_t sum[N]);
