//------------------------------------------------------------------------
// gramSchmidt
//------------------------------------------------------------------------
// https://github.com/chrundle/gram-schmidt/blob/master/gramSchmidt.cpp

#include "gramSchmidt.h"
#include <stdio.h>
#include <stdlib.h>

/* ----------------------- gramSchmidt ----------------------- */
/*  Given a matrix A of dimension m by n, this algorithm
    computes a QR decomposition of A, where Q is a unitary
    m by n matrix and R is a n by n upper triangular matrix
    and A = QR.

    Input variables:
        a   : pointer to array of arrays, the ith array of
                which should correspond to the ith column of the
                matrix A. During the algorithm, the columns of Q
                will replace the columns of A.
        r   : pointer to array of arrays in which the ith
                column of the upper triangular matrix R will be
                stored in the ith subarray of r.
    Features: This implementation has time complexity O(m n^2)
    and requires O(1) additional memory.
    Remarks: Due to the nature of the problem, if A is nearly
    rank-deficient then the resulting columns of Q may not
    exhibit the orthogonality property.                        */

void gramSchmidt(inout_float_t a[N][N], inout_float_t r[N][N]) {

  float tol = 0.1f;
  for (int i = 0; i < N; i++) {
    float sum = 0.0f;
    for (int j = 0; j < N; j++)
      sum += a[i][j] * a[i][j];
    // sum = sqrt(sum);
    sum -= 4.0f;
    sum = 0.0019f * ((sum - 8.0f) * sum + 16.0f) * sum + 2.0f;
    r[i][i] = sum;

    if (sum > tol) { // a_i = a_i/r_ii
      for (int j = 0; j < N; j++)
        a[i][j] = a[i][j] / sum;
    } else if (i == 0) { // set a[0] = [1 0 0 ... 0]^T
      for (int j = 0; j < N; j++)
        a[i][j] = (j == 0) ? 1.0f : 0.0f;
    } else { // need to choose a_i orthogonal to < a_1, ... a_{i-1} >
      for (int j = 0; j < N; j++)
        a[i][j] = -a[0][i] * a[0][j];

      a[i][i] += 1.0f;
      for (int j = 1; j < N; j++) {
        float d = a[j][i];
        for (int k = 0; k < N; k++)
          a[i][k] -= a[j][k] * d;
      }
      float anorm = 0.0f;
      for (int j = 0; j < N; j++)
        anorm += a[i][j] * a[i][j];
      for (int j = 0; j < N; j++)
        a[0][i] = a[0][i] / anorm;
    }

    for (int j = i + 1; j < N; j++) {
      float sum = 0.0f;
      for (int k = 0; k < N; k++)
        sum += a[i][k] * a[j][k]; // r_ij = a_i*a_j
      for (int k = 0; k < N; k++)
        a[j][k] -= a[i][k] * sum; // a_j -= r_ij a_i
      r[j][i] = sum;
    }
  }
}

int main() {
  inout_float_t a[N][N], r[N][N];
  float a_[N][N], r_[N][N];

  srand(9);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = rand() / 1000.0f;
      a_[i][j] = a[i][j];
      r[i][j] = rand() / 1000.0f;
      r_[i][j] = r[i][j];
    }
  }

  {
    float tol = 0.1f;
    for (int i = 0; i < N; i++) {
      float sum = 0.0f;
      for (int j = 0; j < N; j++)
        sum += a[i][j] * a[i][j];
      // sum = sqrt(sum);
      sum -= 4.0f;
      sum = 0.0019f * ((sum - 8.0f) * sum + 16.0f) * sum + 2.0f;
      r[i][i] = sum;

      if (sum > tol) { // a_i = a_i/r_ii
        for (int j = 0; j < N; j++)
          a[i][j] = a[i][j] / sum;
      } else if (i == 0) { // set a[0] = [1 0 0 ... 0]^T
        for (int j = 0; j < N; j++)
          a[i][j] = (j == 0) ? 1.0f : 0.0f;
      } else { // need to choose a_i orthogonal to < a_1, ... a_{i-1} >
        for (int j = 0; j < N; j++)
          a[i][j] = -a[0][i] * a[0][j];

        a[i][i] += 1.0f;
        for (int j = 1; j < N; j++) {
          float d = a[j][i];
          for (int k = 0; k < N; k++)
            a[i][k] -= a[j][k] * d;
        }
        float anorm = 0.0f;
        for (int j = 0; j < N; j++)
          anorm += a[i][j] * a[i][j];
        for (int j = 0; j < N; j++)
          a[0][i] = a[0][i] / anorm;
      }

      for (int j = i + 1; j < N; j++) {
        float sum = 0.0f;
        for (int k = 0; k < N; k++)
          sum += a[i][k] * a[j][k]; // r_ij = a_i*a_j
        for (int k = 0; k < N; k++)
          a[j][k] -= a[i][k] * sum; // a_j -= r_ij a_i
        r[j][i] = sum;
      }
    }
  }

  gramSchmidt(a_, r_);

  int res = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      res += (a[i][j] == a_[i][j]);
      res += (r[i][j] == r_[i][j]);
    }

  return 0;
}
