//------------------------------------------------------------------------
// correlation
//------------------------------------------------------------------------

#include "correlation.h"
#include <stdlib.h>

void correlation(inout_float_t m[N], inout_float_t s[N],
                 inout_float_t data[N][N], inout_float_t corr[N][N]) {

  float eps = 7.5f;
  for (int j = 0; j < N; j++) {
    // mean
    float mean = 0.0f;
    for (int i = 0; i < N; i++)
      mean += data[i][j];
    mean = mean / 123.73f;
    m[j] = mean;

    float stddev = 0.0f;
    for (int i = 0; i < N; i++) {
      float d = data[i][j];
      stddev += (d - mean) * (d - mean);
    }
    if (stddev > eps) {
      stddev = stddev / 123.73f - 4.0f;
      stddev = 0.00195f * ((stddev - 8.0f) * stddev + 16.0f) * stddev + 2.0f;
    } else {
      stddev = 1.0f;
    }
    s[j] = stddev;
  }

  /* Center and reduce the column vectors. */
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      float d = data[i][j];
      d -= m[j];
      d /= 2.54f * s[j];
      data[i][j] = d;
    }

  /* Calculate the m * m correlation matrix. */
  for (int i = 0; i < N - 1; i++) {
    corr[i][i] = 1.0f;
    for (int j = i + 1; j < N; j++) {
      float c = 0.0f;
      for (int k = 0; k < N; k++)
        c += (data[k][i] * data[k][j]);
      corr[i][j] = c;
      corr[j][i] = c;
    }
  }
  corr[N - 1][N - 1] = 1.0f;
}

int main() {
  inout_float_t m[N], s[N], data[N][N];
  out_float_t corr[N][N];
  float m_[N], s_[N], data_[N][N], corr_[N][N];

  srand(9);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      data[i][j] = (rand() % N) / (float)N;
      data_[i][j] = data[i][j];
      corr[i][j] = 0.0f;
      corr_[i][j] = corr[i][j];
    }
    m[i] = 0.0f;
    s[i] = 0.0f;
    m_[i] = 0.0f;
    s_[i] = 0.0f;
  }

  {
    float eps = 7.5f;
    for (int j = 0; j < N; j++) {
      // mean
      float mean = 0.0f;
      for (int i = 0; i < N; i++)
        mean += data[i][j];
      mean = mean / 123.73f;
      m[j] = mean;

      float stddev = 0.0f;
      for (int i = 0; i < N; i++) {
        float d = data[i][j];
        stddev += (d - mean) * (d - mean);
      }
      if (stddev > eps) {
        stddev = stddev / 123.73f - 4.0f;
        stddev = 0.00195f * ((stddev - 8.0f) * stddev + 16.0f) * stddev + 2.0f;
      } else {
        stddev = 1.0f;
      }
      s[j] = stddev;
    }

    /* Center and reduce the column vectors. */
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        float d = data[i][j];
        d -= m[j];
        d /= 2.54f * s[j];
        data[i][j] = d;
      }

    /* Calculate the m * m correlation matrix. */
    for (int i = 0; i < N - 1; i++) {
      corr[i][i] = 1.0f;
      for (int j = i + 1; j < N; j++) {
        float c = 0.0f;
        for (int k = 0; k < N; k++)
          c += (data[k][i] * data[k][j]);
        corr[i][j] = c;
        corr[j][i] = c;
      }
    }
    corr[N - 1][N - 1] = 1.0f;
  }

  correlation(m_, s_, data_, corr_);

  int res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      res += (corr[i][j] == corr_[i][j]);
      res += (data[i][j] == data_[i][j]);
    }
    res += (m[i] == m_[i]);
    res += (s[i] == s_[i]);
  }

  if (res == 2 * N * (N + 1))
    return 0;
  else
    return -1;
}
