//------------------------------------------------------------------------
// syr2k
//------------------------------------------------------------------------

#include "syr2k.h"
#include <stdlib.h>

void syr2k(in_float_t A[N][N], in_float_t B[N][N], inout_float_t C[N][N]) {

  float alpha = 0.73f, beta = 1.96f;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      float sum = C[i][j] * beta;
      for (int k = 0; k < N; k++)
        sum += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
      C[i][j] = sum;
    }
  }
}

int main() {
  inout_float_t C[N][N];
  in_float_t A[N][N], B[N][N];
  float A_[N][N], B_[N][N], C_[N][N];

  srand(9);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = rand();
      A_[i][j] = A[i][j];
      B[i][j] = rand();
      B_[i][j] = B[i][j];
      C[i][j] = rand();
      C_[i][j] = C[i][j];
    }
  }

  {
    float alpha = 0.73f, beta = 1.96f;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= i; j++) {
        float sum = C[i][j] * beta;
        for (int k = 0; k < N; k++)
          sum += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
        C[i][j] = sum;
      }
    }
  }

  syr2k(A_, B_, C_);

  int res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      res += (A[i][j] == A_[i][j]);
      res += (B[i][j] == B_[i][j]);
      res += (C[i][j] == C_[i][j]);
    }
  }

  if (res == 3 * N * N)
    return 0;
  else
    return -1;
}
