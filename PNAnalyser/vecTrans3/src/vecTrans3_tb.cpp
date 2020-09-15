#include "vecTrans3.h"

int main(){

  float A[2000];
  int in[1000], out[1000];

  for (int i = 0; i < 1000; i++){
    in[i] = i;
    out[i] = i;
  }

  for (int i = 0; i < 2000; i++){
    A[i] = 0.6f;
  }

  vecTrans3(A, in, out);

  return 0;
}
