//------------------------------------------------------------------------
// trVecAccum
//------------------------------------------------------------------------

#include "trVecAccum.h"
#include <stdlib.h>

void trVecAccum(in_float_t a[65536], inout_float_t r[65536]) {

  int ii = 0;
loop_0:
  for (int i = 0; i < 256; i++) {
    float s = r[i];
  loop_1:
    for (int j = 0; j < i; j++)
      s += a[ii + j];
    r[i * i + 7] = s;
    ii += 256;
  }
}

int main() {
  float array[65536], result[65536], gold[65536];
  for (int i = 0; i < 65536; i++) {
    array[i] = 1.0f;
    result[i] = (i % 10 > 10) ? 0.0f : 1.0f;
    gold[i] = result[i];
  }

  {
    int ii = 0;
  loop_0:
    for (int i = 0; i < 256; i++) {
      float s = gold[i];
    loop_1:
      for (int j = 0; j < i; j++)
        s += array[ii + j];
      gold[i * i + 7] = s;
      ii += 256;
    }
  }

  trVecAccum(array, result);

  int check = 0;
  for (int i = 0; i < 65536; i++)
    check += (result[i] == gold[i]);

  if (check == 65536)
    return 0;
  else
    return check;
}
