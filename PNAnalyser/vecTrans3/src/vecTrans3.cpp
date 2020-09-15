#include "vecTrans3.h"

void vecTrans3(float A[2000], int in[1000], int out[1000]){
  for (int i = 0; i <1000; i++)
  {
    float d = A[in[i]];
    A[out[i]] = g(d);
  }
}
