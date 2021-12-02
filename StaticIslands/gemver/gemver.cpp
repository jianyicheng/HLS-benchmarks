//------------------------------------------------------------------------
// gemver
//------------------------------------------------------------------------

#include "gemver.h"
#include <stdlib.h>

void gemver(inout_float_t A[N][N], in_float_t u1[N], in_float_t v1[N],
            in_float_t u2[N], in_float_t v2[N], inout_float_t w[N],
            inout_float_t x[N], in_float_t y[N], in_float_t z[N]) {

  float alpha = 0.73f, beta = 0.69f;
  for (int i = 0; i < N; i++) {
    float u11 = u1[i];
    float u22 = u2[i];
    for (int j = 0; j < N; j++)
      A[i][j] += u11 * v1[j] + u22 * v2[j];
  }

  for (int i = 0; i < N; i++) {
    float tmp = x[i];
    for (int j = 0; j < N; j++)
      tmp += beta * A[j][i] * y[j];
    x[i] = tmp + z[i];
  }

  for (int i = 0; i < N; i++) {
    float tmp = w[i];
    for (int j = 0; j < N; j++)
      tmp = tmp + alpha * A[i][j] * x[j];
    w[i] = tmp;
  }
}

int main(void) {
  inout_float_t A[N][N], A_[N][N];
  in_float_t u1[N];
  in_float_t v1[N];
  in_float_t u2[N];
  in_float_t v2[N];
  inout_float_t w[N], w_[N];
  inout_float_t x[N], x_[N];
  in_float_t y[N];
  in_float_t z[N];

  srand(9);

  for (int i = 0; i < N; ++i) {
    u1[i] = rand();
    v1[i] = rand();
    u2[i] = rand();
    v2[i] = rand();
    w[i] = rand();
    x[i] = rand();
    w_[i] = rand();
    x_[i] = rand();
    y[i] = rand();
    z[i] = rand();
    for (int x = 0; x < N; ++x) {
      A[i][x] = rand();
      A_[i][x] = A[i][x];
    }
  }

  {
    float alpha = 0.73f, beta = 0.69f;
    for (int i = 0; i < N; i++) {
      float u11 = u1[i];
      float u22 = u2[i];
      for (int j = 0; j < N; j++)
        A[i][j] += u11 * v1[j] + u22 * v2[j];
    }

    for (int i = 0; i < N; i++) {
      float tmp = x[i];
      for (int j = 0; j < N; j++)
        tmp += beta * A[j][i] * y[j];
      x[i] = tmp + z[i];
    }

    for (int i = 0; i < N; i++) {
      float tmp = w[i];
      for (int j = 0; j < N; j++)
        tmp = tmp + alpha * A[i][j] * x[j];
      w[i] = tmp;
    }
  }

  gemver(A_, u1, v1, u2, v2, w_, x_, y, z);

  int res = 0;
  for (int j = 0; j < N; j++)
    res += (w[j] == w_[j]);

  if (res == N)
    return 0;
  else
    return -1;
}
