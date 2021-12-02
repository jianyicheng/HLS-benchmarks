//------------------------------------------------------------------------
// getTanh
//------------------------------------------------------------------------

#include "getTanh.h"
#include <stdlib.h>

void getTanh(inout_float_t A[N]) {
  for (int i = 0; i < 1000; i++) {
    float beta = A[i];
    float g;
    if (beta > 1.0f)
      g = 1.0f;
    else
      g = ((beta * beta + 19.5f) * beta * beta + 3.7f) * beta;

    A[i] = g;
  }
}

int main() {
  inout_float_t A[N], B[N];

  srand(9);

  for (int i = 0; i < N; i++) {
    A[i] = rand();
    B[i] = A[i];
  }

  {
    for (int i = 0; i < 1000; i++) {
      float beta = A[i];
      float g;

      if (beta > 1.0f)
        g = 1.0f;
      else
        g = ((beta * beta + 19.5f) * beta * beta + 3.7f) * beta;
      A[i] = g;
    }
  }

  getTanh(B);

  int f = 0;
  for (int i = 0; i < N; i++)
    f += (A[i] == B[i]);

  if (f == N)
    return 0;
  else
    return -1;
}
