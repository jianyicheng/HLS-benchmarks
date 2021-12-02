#include "doitgenTriple.h"

//------------------------------------------------------------------------
// doitgenTriple
//------------------------------------------------------------------------

// SEPARATOR_FOR_MAIN

#include "doitgenTriple.h"
#include <stdlib.h>

void doitgenTriple(inout_float_t A[N], in_float_t w[N][N],
                   inout_float_t sum[N]) {
loop_0:
  for (int i = 0; i < N; i++) {
    float s = 0;
  loop_1:
    for (int j = 0; j < N; j++) {
      float a = A[j];
      float wt = w[i][j];
      if (a > 0.0) {
        s += (a * wt + wt) * a;
      }
    }
    sum[i] = s;
  }
loop_2:
  for (int i = 0; i < N - 1; i++) {
    float q = sum[i];
    A[i + 1] = A[i] + q * q * q;
  }
}

int main() {
  float A[N], B[N], sum[N], sum_[N], w[N][N];
  srand(9);

  for (int i = 0; i < N; i++) {
    A[i] = rand();
    B[i] = A[i];
    for (int j = 0; j < N; j++)
      w[i][j] = rand();
    sum[i] = 0;
    sum_[i] = 0;
  }

loop_0:
  for (int i = 0; i < N; i++) {
    float s = 0;
  loop_1:
    for (int j = 0; j < N; j++) {
      float a = B[j];
      float wt = w[i][j];
      if (a > 0.0) {
        s += (a * wt + wt) * a;
      }
    }
    sum_[i] = s;
  }
loop_2:
  for (int i = 0; i < N - 1; i++) {
    float q = sum_[i];
    B[i + 1] = B[i] + q * q * q;
  }

  doitgenTriple(A, w, sum);

  int f = 0;
  for (int i = 0; i < N; i++)
    f += (A[i] == B[i]);

  if (f == N)
    return 0;
  else
    return -1;
}
