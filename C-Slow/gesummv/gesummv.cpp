//------------------------------------------------------------------------
// gesummv
//------------------------------------------------------------------------

#include "gesummv.h"
#include <stdlib.h>

void gesummv(in_float_t A[65536], in_float_t B[65536], out_float_t tmp[256],
             out_float_t y[256], in_float_t x[256]) {

  float alpha = 0.73f, beta = 1.63f;

  int ii = 0;
  for (int i = 0; i < N; i++) {
    float t_tmp = 0.0f;
    float t_y = 0.0f;

  loop_2:
    for (int j = 0; j < N; j++) {
      float t_x = x[j];
      t_tmp = A[ii + j] * t_x + t_tmp;
      t_y = B[ii + j] * t_x + t_y;
    }

    tmp[i] = t_tmp;
    y[i] = alpha * t_tmp + beta * t_y;
    ii += N;
  }
}

int main(void) {
  in_float_t A[65536];
  in_float_t B[65536];
  out_float_t tmp[256], tmp_[256];
  out_float_t y[256], y_[256];
  in_float_t x[256];

  for (int yy = 0; yy < 256; ++yy) {
    x[yy] = 0.1f;
    y[yy] = 0.1f;
    tmp[yy] = 0.1f;

    y_[yy] = y[yy];
    tmp_[yy] = tmp[yy];

    for (int x = 0; x < 256; ++x) {
      A[yy * 256 + x] = 0.2f;
      B[yy * 256 + x] = A[yy * 256 + x];
    }
  }

  {
    float alpha = 0.73f, beta = 1.63f;

    int ii = 0;
    for (int i = 0; i < N; i++) {
      float t_tmp = 0.0f;
      float t_y = 0.0f;

      for (int j = 0; j < N; j++) {
        float t_x = x[j];
        t_tmp = A[ii + j] * t_x + t_tmp;
        t_y = B[ii + j] * t_x + t_y;
      }

      tmp_[i] = t_tmp;
      y_[i] = alpha * t_tmp + beta * t_y;
      ii += N;
    }
  }

  gesummv(A, B, tmp, y, x);

  return 0;
}
