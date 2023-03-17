typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 32
void correlation(inout_float_t m[32], inout_float_t s[32],
                 inout_float_t data[1024], inout_float_t corr[1024]);
