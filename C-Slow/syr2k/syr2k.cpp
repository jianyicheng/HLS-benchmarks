//------------------------------------------------------------------------
// syr2k
//------------------------------------------------------------------------

#include "syr2k.h"
#include <stdlib.h>

void syr2k(in_float_t A[1024], in_float_t B[1024], inout_float_t C[1024]) {
  float alpha = 0.73f, beta = 1.96f;
  int ii = 0;
  for (int i = 0; i < N; i++) {
    int jj = 0;
    for (int j = 0; j <= i; j++) {
      int idx = ii + j;
      float sum = C[idx] * beta;
    loop_2:
      for (int k = 0; k < N; k++)
        sum += A[jj + k] * alpha * B[ii + k] + B[jj + k] * alpha * A[ii + k];
      C[idx] = sum;
      jj += N;
    }
    ii += N;
  }
}

int main() {
  inout_float_t C[1024];
  in_float_t A[1024], B[1024];
  float A_[1024], B_[1024], C_[1024];

  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      A[i * 32 + j] = 0.1f;
      A_[i * 32 + j] = A[i * 32 + j];
      B[i * 32 + j] = 0.1f;
      B_[i * 32 + j] = B[i * 32 + j];
      C[i * 32 + j] = 0.1f;
      C_[i * 32 + j] = C[i * 32 + j];
    }
  }

  {
    float alpha = 0.73f, beta = 1.96f;
    int ii = 0;
    for (int i = 0; i < N; i++) {
      int jj = 0;
      for (int j = 0; j <= i; j++) {
        float sum = C_[ii + j] * beta;
        for (int k = 0; k < N; k++)
          sum +=
              A_[jj + k] * alpha * B_[ii + k] + B_[jj + k] * alpha * A_[ii + k];
        C_[ii + j] = sum;
        jj += N;
      }
      ii += N;
    }
  }

  syr2k(A, B, C);

  return 0;
}
