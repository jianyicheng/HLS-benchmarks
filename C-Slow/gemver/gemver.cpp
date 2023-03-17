//------------------------------------------------------------------------
// gemver
//------------------------------------------------------------------------

#include "gemver.h"
#include <stdlib.h>

void gemver(inout_float_t A[65536], in_float_t u1[256], in_float_t v1[256],
            in_float_t u2[256], in_float_t v2[256], inout_float_t w[256],
            inout_float_t x[256], in_float_t y[256], in_float_t z[256]) {

  float alpha = 0.73f, beta = 0.69f;
  int ii = 0;
  for (int i = 0; i < N; i++) {
    float u11 = u1[i];
    float u22 = u2[i];
  loop_2:
    for (int j = 0; j < N; j++)
      A[ii + j] += u11 * v1[j] + u22 * v2[j];
    ii += N;
  }

  for (int i = 0; i < N; i++) {
    float tmp = x[i];
    int jj = 0;
  loop_3:
    for (int j = 0; j < N; j++) {
      tmp += beta * A[jj + i] * y[j];
      jj += N;
    }
    x[i] = tmp + z[i];
  }

  int kk = 0;
  for (int i = 0; i < N; i++) {
    float tmp = w[i];
  loop_4:
    for (int j = 0; j < N; j++)
      tmp = tmp + alpha * A[kk + j] * x[j];
    w[i] = tmp;
    kk += N;
  }
}

int main(void) {
  inout_float_t A[65536], A_[65536];
  in_float_t u1[256];
  in_float_t v1[256];
  in_float_t u2[256];
  in_float_t v2[256];
  inout_float_t w[256], w_[256];
  inout_float_t x[256], x_[256];
  in_float_t y[256];
  in_float_t z[256];

  for (int yy = 0; yy < N; ++yy) {
    u1[yy] = 0.1f;
    v1[yy] = 0.1f;
    u2[yy] = 0.1f;
    v2[yy] = 0.1f;
    w[yy] = 0.1f;
    x[yy] = 0.1f;
    w_[yy] = 0.1f;
    x_[yy] = 0.1f;
    y[yy] = 0.1f;
    z[yy] = 0.1f;
    for (int x = 0; x < N; ++x) {
      A[yy * N + x] = 0.2f;
      A_[yy * N + x] = 0.2f;
    }
  }

  {
    float alpha = 0.73f, beta = 0.69f;
    int ii = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        A_[ii + j] += u1[i] * v1[j] + u2[i] * v2[j];
      ii += N;
    }

    for (int i = 0; i < N; i++) {
      float tmp = x_[i];
      int jj = 0;
      for (int j = 0; j < N; j++) {
        tmp += beta * A_[jj + i] * y[j];
        jj += N;
      }
      x_[i] = tmp + z[i];
    }

    int kk = 0;
    for (int i = 0; i < N; i++) {
      float tmp = w_[i];
      for (int j = 0; j < N; j++)
        tmp = tmp + alpha * A_[kk + j] * x_[j];
      w_[i] = tmp;
      kk += N;
    }
  }

  gemver(A, u1, v1, u2, v2, w, x, y, z);

  int res = 0;
  for (int j = 0; j < N; j++)
    res += (w[j] == w_[j]);

  if (res == N)
    return 0;
  else
    return -1;
}
