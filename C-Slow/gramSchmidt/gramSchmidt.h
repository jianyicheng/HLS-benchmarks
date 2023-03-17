typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

#define N 32

void gramSchmidt(inout_float_t a[1024], inout_float_t r[1024],
                 inout_float_t q[1024]);
