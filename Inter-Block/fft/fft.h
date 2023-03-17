typedef float in_float_t;
typedef float out_float_t;
typedef float inout_float_t;

void fft(inout_float_t X_R_0[1024], inout_float_t X_R_1[1024],
         inout_float_t X_R_2[1024], inout_float_t X_R_3[1024],
         inout_float_t X_R_4[1024], inout_float_t X_R_5[1024],
         inout_float_t X_R_6[1024], inout_float_t X_R_7[1024],
         inout_float_t X_I_0[1024], inout_float_t X_I_1[1024],
         inout_float_t X_I_2[1024], inout_float_t X_I_3[1024],
         inout_float_t X_I_4[1024], inout_float_t X_I_5[1024],
         inout_float_t X_I_6[1024], inout_float_t X_I_7[1024],
         in_float_t cos_coefficients_table[512],
         in_float_t sin_coefficients_table[512]);
