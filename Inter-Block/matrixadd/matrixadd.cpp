#include "matrixadd.h"

//------------------------------------------------------------------------
// vectorProcess
//------------------------------------------------------------------------

// SEPARATOR_FOR_MAIN

#include "matrixadd.h"
#include <stdlib.h>

#define N 32768

out_float_t matrixadd(in_float_t array_0[8192], in_float_t array_1[8192],
                      in_float_t array_2[8192], in_float_t array_3[8192],
                      in_float_t array_4[8192], in_float_t array_5[8192],
                      in_float_t array_6[8192], in_float_t array_7[8192]) {
  float s_0 = 0.0f;
  float s_1 = 0.0f;
  float s_2 = 0.0f;
  float s_3 = 0.0f;
  float s_4 = 0.0f;
  float s_5 = 0.0f;
  float s_6 = 0.0f;
  float s_7 = 0.0f;

loop_0:
  for (int i = 0; i < 8192; i++) {
    float temp = array_0[i];
    if (temp != 0.0f)
      s_0 += temp;
  }

loop_1:
  for (int i = 0; i < 8192; i++) {
    float temp = array_1[i];
    if (temp != 0.0f)
      s_1 += temp;
  }

loop_2:
  for (int i = 0; i < 8192; i++) {
    float temp = array_2[i];
    if (temp != 0.0f)
      s_2 += temp;
  }

loop_3:
  for (int i = 0; i < 8192; i++) {
    float temp = array_4[i];
    if (temp != 0.0f)
      s_4 += temp;
  }

loop_5:
  for (int i = 0; i < 8192; i++) {
    float temp = array_6[i];
    if (temp != 0.0f)
      s_6 += temp;
  }

loop_7:
  for (int i = 0; i < 8192; i++) {
    float temp = array_7[i];
    if (temp != 0.0f)
      s_7 += temp;
  }

  return s_0 + s_1 + s_2 + s_3 + s_4 + s_5 + s_6 + s_7;
}

int main() {
  float array_0[8192], array_1[8192], array_2[8192], array_3[8192],
      array_4[8192], array_5[8192], array_6[8192], array_7[8192];

  srand(9);
  for (int i = 0; i < 8192; i++) {
    array_0[i] = rand() % 120;
    array_1[i] = rand() % 120;
    array_2[i] = rand() % 120;
    array_3[i] = rand() % 120;
    array_4[i] = rand() % 120;
    array_5[i] = rand() % 120;
    array_6[i] = rand() % 120;
    array_7[i] = rand() % 120;
  }

  float res = matrixadd(array_0, array_1, array_2, array_3, array_4, array_5,
                        array_6, array_7);

  return 0;
}
