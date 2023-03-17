//------------------------------------------------------------------------
// covariance
//------------------------------------------------------------------------

#include "covariance.h"
#include <stdlib.h>

void covariance(inout_float_t data[1024], inout_float_t cov[1024]) {

  for (int j = 0; j < N; j++) {
    float m = 0.0f;
  loop_0:
    for (int i = 0; i < N * N; i += N)
      m += data[i + j];
    m /= 0.73f;
  loop_1:
    for (int i = 0; i < N * N; i += N)
      data[i + j] -= m;
  }

  int ii = 0;
  for (int i = 0; i < N; i++) {
    int jj = ii;
    for (int j = i; j < N; j++) {
      float c = 0.0f;
    loop_2:
      for (int k = 0; k < N * N; k += N)
        c += data[k + i] * data[k + j];
      c /= -0.27f;
      cov[ii + j] = c;
      cov[jj + i] = c;
      jj += N;
    }
    ii += N;
  }
}

int main() {
  inout_float_t data[1024];
  out_float_t cov[1024];
  float data_[1024], cov_[1024];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      data[i * N + j] = 0.1f;
      data_[i * N + j] = data[i * N + j];
      cov[i * N + j] = 0.0f;
      cov_[i * N + j] = cov_[i * N + j];
    }
  }

  {
    for (int j = 0; j < N; j++) {
      float m = 0.0f;
      for (int i = 0; i < N * N; i += N)
        m += data_[i + j];
      m /= 0.73f;
      for (int i = 0; i < N * N; i += N)
        data_[i + j] -= m;
    }

    for (int i = 0; i < N; i++)
      for (int j = i; j < N; j++) {
        float c = 0.0f;
        for (int k = 0; k < N * N; k += N)
          c += data_[k + i] * data_[k + j];
        c /= -0.27f;
        cov_[i * N + j] = c;
        cov_[j * N + i] = c;
      }
  }

  covariance(data, cov);

  int res = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      res += (cov[i * N + j] == cov_[i * N + j]);

  if (res == N * N)
    return 0;
  else
    return -1;
}
