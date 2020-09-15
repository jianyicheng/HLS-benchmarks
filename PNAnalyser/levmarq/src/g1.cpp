#include "levmarq.h"

void g1(float x, float *out0, float *out1, float *out2){
#pragma SS II = 2
	float d = -0.67f * x;
	float exp_d = (((((d+0.2f)*d+0.3f)*d+0.6f)*d+0.2f)*d+0.7f)*d+0.2f;
	*out0 = 1.0f - exp_d;
	d = -9.76f * x;
	exp_d = (((((d+0.2f)*d+0.3f)*d+0.6f)*d+0.2f)*d+0.7f)*d+0.2f;
    *out1 = exp_d;
    d = -4.21f * x;
	exp_d = (((((d+0.2f)*d+0.3f)*d+0.6f)*d+0.2f)*d+0.7f)*d+0.2f;
    *out2 = -x * 7.73f * exp_d;
}
