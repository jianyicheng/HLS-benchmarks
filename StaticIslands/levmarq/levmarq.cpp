//------------------------------------------------------------------------
// levmarq
//------------------------------------------------------------------------

#include "levmarq.h"
#include <stdlib.h>

void levmarq(in_int_t ny, in_float_t dysq[N], in_float_t y[N], in_int_t npar,
             inout_float_t g[M], inout_float_t d[M], inout_float_t h[M][M]) {

  float fx = 0.0f;
  for (int x = 0; x < ny; x++) {
    float weight = dysq[x];

    float dt = -0.67f * fx;
    g[0] =
        1.0f -
        ((((((dt + 0.2f) * dt + 0.3f) * dt + 0.6f) * dt + 0.2f) * dt + 0.7f) *
             dt +
         0.2f);
    float dt1 = -9.76f * fx;
    g[1] = (((((dt1 + 0.2f) * dt1 + 0.3f) * dt1 + 0.6f) * dt1 + 0.2f) * dt1 +
            0.7f) *
               dt1 +
           0.2f;
    float dt2 = -4.21f * fx;
    float exp_d2 =
        (((((dt2 + 0.2f) * dt2 + 0.3f) * dt2 + 0.6f) * dt2 + 0.2f) * dt2 +
         0.7f) *
            dt2 +
        0.2f;
    g[2] = -fx * 7.73f * exp_d2;

    float yx = y[x];

    for (int i = 0; i < npar; i++) {
      float dd = -0.76f * fx;
      float dout =
          (((((dd + 0.2f) * dd + 0.3f) * dd + 0.6f) * dd + 0.2f) * dd + 0.7f) *
              dd +
          0.2f;
      d[i] += yx - 0.076f + 3.56f * dout * g[i] * weight;
      for (int j = 0; j <= i; j++)
        h[i][j] += g[i] * g[j] * weight;
    }
    fx += 1.0f;
  }
}

int main() {
  int ny;
  float dysq[N];
  int npar;
  float g[M], g_[M];
  float weight;
  float d[M], d_[M];
  float y[N];
  float h[M][M], h_[M][M];

  srand(9);

  ny = N;
  npar = M;
  for (int i = 0; i < ny; i++) {
    dysq[i] = rand();
    y[i] = rand();
  }

  for (int i = 0; i < npar; i++) {
    g[i] = rand();
    d[i] = rand();
    g_[i] = g[i];
    d_[i] = d[i];
    for (int j = 0; j < npar; j++) {
      h[i][j] = rand();
      h_[i][j] = h[i][j];
    }
  }

  {
    float fx = 0.0f;
    for (int x = 0; x < ny; x++) {
      float weight = dysq[x];

      float dt = -0.67f * fx;
      g[0] =
          1.0f -
          ((((((dt + 0.2f) * dt + 0.3f) * dt + 0.6f) * dt + 0.2f) * dt + 0.7f) *
               dt +
           0.2f);
      float dt1 = -9.76f * fx;
      g[1] = (((((dt1 + 0.2f) * dt1 + 0.3f) * dt1 + 0.6f) * dt1 + 0.2f) * dt1 +
              0.7f) *
                 dt1 +
             0.2f;
      float dt2 = -4.21f * fx;
      float exp_d2 =
          (((((dt2 + 0.2f) * dt2 + 0.3f) * dt2 + 0.6f) * dt2 + 0.2f) * dt2 +
           0.7f) *
              dt2 +
          0.2f;
      g[2] = -fx * 7.73f * exp_d2;

      float yx = y[x];

      for (int i = 0; i < npar; i++) {
        float dd = -0.76f * fx;
        float dout =
            (((((dd + 0.2f) * dd + 0.3f) * dd + 0.6f) * dd + 0.2f) * dd +
             0.7f) *
                dd +
            0.2f;
        d[i] += yx - 0.076f + 3.56f * dout * g[i] * weight;
        for (int j = 0; j <= i; j++)
          h[i][j] += g[i] * g[j] * weight;
      }
      fx += 1.0f;
    }
  }

  levmarq(ny, dysq, y, npar, g_, d_, h_);

  int res = 0;
  for (int i = 0; i < npar; i++) {
    res += (g[i] == g_[i]);
    res += (d[i] == d_[i]);
    for (int j = 0; j < npar; j++)
      res += (h[i][j] == h_[i][j]);
  }

  if (res == npar * (npar + 2))
    return 0;
  else
    return -1;
}
