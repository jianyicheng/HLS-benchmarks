//------------------------------------------------------------------------
// correlation
//------------------------------------------------------------------------
// Run DS: dass-baseline correlation false

#include "correlation.h"
#include <stdio.h>
#include <stdlib.h>

#define N_END N *(N - 1) + N - 1

void correlation(inout_float_t m[32], inout_float_t s[32],
                 inout_float_t data[1024], inout_float_t corr[1024]) {

  float eps = 7.5f;
loop_0:
  for (int j = 0; j < N; j++) {
    float mean = 0.0f;
  loop_1:
    for (int i = 0; i < N * N; i += N)
      mean += data[i + j];
    mean = mean / 123.73f;
    m[j] = mean;

    float stddev = 0.0f;
  loop_2:
    for (int i = 0; i < N * N; i += N) {
      float d = data[i + j];
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
  for (int i = 0; i < N * N; i += N) {
  loop_3:
    for (int j = 0; j < N; j++) {
      int idx = i + j;
      float d = data[idx];
      d -= m[j];
      d /= 2.54f * s[j];
      data[idx] = d;
    }
  }

  /* Calculate the m * m correlation matrix. */
  int ii = 0;
  for (int i = 0; i < N - 1; i++) {
    corr[ii + i] = 1.0f;
    int jj = 0;
    for (int j = i + 1; j < N; j++) {
      float c = 0.0f;
    loop_4:
      for (int k = 0; k < N * N; k += N)
        c += (data[k + i] * data[k + j]);
      corr[ii + j] = c;
      corr[jj + i] = c;
      jj += N;
    }
    ii += N;
  }
  corr[N_END] = 1.0f;
}

int main() {
  inout_float_t m[32], s[32], data[1024];
  out_float_t corr[1024];
  float m_[32], s_[32], data_[1024], corr_[1024];

  srand(9);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      data[i * N + j] = (rand() % N) / (float)N;
      data_[i * N + j] = data[i * N + j];
      corr[i * N + j] = 0.0f;
      corr_[i * N + j] = corr[i * N + j];
    }
    m[i] = 0.0f;
    s[i] = 0.0f;
    m_[i] = 0.0f;
    s_[i] = 0.0f;
  }

  {
    int a = 0, b = 0;
    float eps = 7.5f;
    for (int j = 0; j < N; j++) {
      // mean
      float mean = 0.0f;
      for (int i = 0; i < N * N; i += N)
        mean += data_[i + j];
      mean = mean / 123.73f;
      m_[j] = mean;

      float stddev = 0.0f;
      for (int i = 0; i < N * N; i += N) {
        float d = data_[i + j];
        stddev += (d - mean) * (d - mean);
      }
      if (stddev > eps) {
        stddev = stddev / 123.73f - 4.0f;
        stddev = 0.00195f * ((stddev - 8.0f) * stddev + 16.0f) * stddev + 2.0f;
        a++;
      } else {
        stddev = 1.0f;
        b++;
      }
      s_[j] = stddev;
    }

    /* Center and reduce the column vectors. */
    for (int i = 0; i < N * N; i += N)
      for (int j = 0; j < N; j++) {
        int idx = i + j;
        float d = data_[idx];
        d -= m_[j];
        d /= 2.54f * s_[j];
        data_[idx] = d;
      }

    /* Calculate the m * m correlation matrix. */
    int ii = 0;
    for (int i = 0; i < N - 1; i++) {
      corr_[ii + i] = 1.0f;
      int jj = 0;
      for (int j = i + 1; j < N; j++) {
        float c = 0.0f;
        for (int k = 0; k < N * N; k += N)
          c += (data_[k + i] * data_[k + j]);
        corr_[ii + j] = c;
        corr_[jj + i] = c;
        jj += N;
      }
      ii += N;
    }
    corr_[N_END] = 1.0f;
  }

  correlation(m, s, data, corr);

  int res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      res += (corr[i * N + j] == corr_[i * N + j]);
      res += (data[i * N + j] == data_[i * N + j]);
    }
    res += (m[i] == m_[i]);
    res += (s[i] == s_[i]);
  }

  if (res == 2 * N * (N + 1))
    return 0;
  else
    return -1;
}
