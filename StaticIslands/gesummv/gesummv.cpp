//------------------------------------------------------------------------
// gesummv
//------------------------------------------------------------------------

#include "gesummv.h"
#include <stdlib.h>

void gesummv(in_float_t A[N][N], in_float_t B[N][N], out_float_t tmp[N],
             out_float_t y[N], in_float_t x[N]) {

  float alpha = 0.73f, beta = 1.63f;

  for (int i = 0; i < N; i++) {
    float t_tmp = 0.0f;
    float t_y = 0.0f;

    for (int j = 0; j < N; j++) {
      float t_x = x[j];
      t_tmp = A[i][j] * t_x + t_tmp;
      t_y = B[i][j] * t_x + t_y;
    }

    tmp[i] = t_tmp;
    y[i] = alpha * t_tmp + beta * t_y;
  }
}

int main(void) {
  in_float_t A[N][N];
  in_float_t B[N][N];
  out_float_t tmp[N], tmp_[N];
  out_float_t y[N], y_[N];
  in_float_t x[N];

  for (int i = 0; i < N; ++i) {
    x[i] = 0.1f;
    y[i] = 0.1f;
    tmp[i] = 0.1f;

    y_[i] = y[i];
    tmp_[i] = tmp[i];

    for (int x = 0; x < N; ++x) {
      A[i][x] = 0.2f;
      B[i][x] = A[i][x];
    }
  }

  {
    float alpha = 0.73f, beta = 1.63f;

    for (int i = 0; i < N; i++) {
      float t_tmp = 0.0f;
      float t_y = 0.0f;

      for (int j = 0; j < N; j++) {
        float t_x = x[j];
        t_tmp = A[i][j] * t_x + t_tmp;
        t_y = B[i][j] * t_x + t_y;
      }

      tmp[i] = t_tmp;
      y[i] = alpha * t_tmp + beta * t_y;
    }
  }

  gesummv(A, B, tmp_, y_, x);

  int res = 0;
  for (int j = 0; j < N; j++) {
    res += (tmp[j] == tmp_[j]);
    res += (y[j] == y_[j]);
  }

  if (res == 2 * N)
    return 0;
  else
    return -1;
}
