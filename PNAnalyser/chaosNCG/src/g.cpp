#include "chaosNCG.h"

void g(int b0, int b1, int p0, int p1, int X, int Y, int *pp0, int *pp1, int *out0, int *out1){
#pragma SS II=2
  p0 ^= b0, p1 ^= b1;
  p1 ^= (Y << (p0 % 17) | Y >> (16 - p0 % 17));
  p0 ^= p1;
  p1 += (X & p0);
  *out0 = b0 - p1;
  p0 += (X << (p1 % 17) | X >> (16 - p1 % 17));
  p1 += p0;
  p0 += (Y & p1);
  *out1 = b1 + p0;
  *pp0 = p0;
  *pp1 = p1;
}


