#include "evalPos.h"

float g(int profile, int i, int moveCount, int benefitMagnitude, int pm){
#pragma SS II=10
	float a = 2.5f - i % 6;
	a = (a > 0)? a : -a;
	float b = 2.5f - i / 6;
	b = (b > 0)? b : -b;
	float c = (a > b)? a : b;
	return benefitMagnitude * c * pm;
}
