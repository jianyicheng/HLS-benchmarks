#include "matrixtrans.h"

//------------------------------------------------------------------------
// vectorProcess
//------------------------------------------------------------------------

// SEPARATOR_FOR_MAIN

#include "matrixtrans.h"
#include <stdlib.h>

#define N 32768
void matrixtrans(in_int_t array_0[8192], in_int_t array_1[8192],
                 in_int_t array_2[8192], in_int_t array_3[8192],
                 in_int_t array_4[8192], in_int_t array_5[8192],
                 in_int_t array_6[8192], in_int_t array_7[8192],
                 out_int_t results_0[8192], out_int_t results_1[8192],
                 out_int_t results_2[8192], out_int_t results_3[8192],
                 out_int_t results_4[8192], out_int_t results_5[8192],
                 out_int_t results_6[8192], out_int_t results_7[8192]) {

loop_0:
  for (int i = 0; i < 8192; i++)
    results_0[i] = array_0[i];

loop_1:
  for (int i = 0; i < 8192; i++)
    results_1[i] = array_1[i];

loop_2:
  for (int i = 0; i < 8192; i++)
    results_2[i] = array_2[i];

loop_3:
  for (int i = 0; i < 8192; i++)
    results_3[i] = array_3[i];

loop_4:
  for (int i = 0; i < 8192; i++)
    results_4[i] = array_4[i];

loop_5:
  for (int i = 0; i < 8192; i++)
    results_5[i] = array_5[i];

loop_6:
  for (int i = 0; i < 8192; i++)
    results_6[i] = array_6[i];

loop_7:
  for (int i = 0; i < 8192; i++)
    results_7[i] = array_7[i];
}

int main() {
  int array_0[8192], array_1[8192], array_2[8192], array_3[8192], array_4[8192],
      array_5[8192], array_6[8192], array_7[8192];
  int results_0[8192], results_1[8192], results_2[8192], results_3[8192],
      results_4[8192], results_5[8192], results_6[8192], results_7[8192];

  for (int i = 0; i < 8192; i++) {
    array_0[i] = rand();
    array_1[i] = rand();
    array_2[i] = rand();
    array_3[i] = rand();
    array_4[i] = rand();
    array_5[i] = rand();
    array_6[i] = rand();
    array_7[i] = rand();
  }

  matrixtrans(array_0, array_1, array_2, array_3, array_4, array_5, array_6,
              array_7, results_0, results_1, results_2, results_3, results_4,
              results_5, results_6, results_7);

  return 0;
}
