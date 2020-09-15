#include "levmarq.h"

float g2(float y, float x, float g, float weight){
#pragma SS II=2
	float d, dout;
	d = -0.76f*x;
	dout = (((((d+0.2f)*d+0.3f)*d+0.6f)*d+0.2f)*d+0.7f)*d+0.2f;
	return y - 0.076f + 3.56f * dout*g*weight; 
}
