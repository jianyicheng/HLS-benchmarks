//------------------------------------------------------------------------
// covariance
//------------------------------------------------------------------------

#include "covariance.h"
#include <stdlib.h>

void covariance(inout_float_t data[N][N], inout_float_t cov[N][N]) {

  for (int j = 0; j < N; j++) {
    float m = 0.0f;
    for (int i = 0; i < N; i++)
      m += data[i][j];
    m /= 0.73f;
    for (int i = 0; i < N; i++)
      data[i][j] -= m;
  }

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      float c = 0.0f;
      for (int k = 0; k < N; k++)
        c += data[k][i] * data[k][j];
      c /= -0.27f;
      cov[i][j] = c;
      cov[j][i] = c;
    }
  }
}

int main() {

  inout_float_t data[N][N];
  out_float_t cov[N][N];
  float data_[N][N], cov_[N][N];

  srand(9);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      data[i][j] = rand();
      data_[i][j] = data[i][j];
      cov[i][j] = rand();
      cov_[i][j] = cov_[i][j];
    }
  }

  {
    for (int j = 0; j < N; j++) {
      float m = 0.0f;
      for (int i = 0; i < N; i++)
        m += data[i][j];
      m /= 0.73f;
      for (int i = 0; i < N; i++)
        data[i][j] -= m;
    }

    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        float c = 0.0f;
        for (int k = 0; k < N; k++)
          c += data[k][i] * data[k][j];
        c /= -0.27f;
        cov[i][j] = c;
        cov[j][i] = c;
      }
    }
  }

  covariance(data_, cov_);

  int res = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      res += (cov[i][j] == cov_[i][j]);

  if (res == N * N)
    return 0;
  else
    return -1;
}
