#include "vecTrans.h"

void vecTrans(int A[1024], int b[1024]) { 
  for (int i = 0; i < 1000; i++) { 
    int d = A[i];
      A[b[i]] = g(d); // need to change the mul to add
  }
}
