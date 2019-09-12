/*

  Benchmark:  getTanh
  FileName:   getTanh.cpp
  Author:     Jianyi Cheng
  Date:       12 Sep 2019

*/

#include "getTanh.h"

void getTanh(int A[1000], int addr_in[1000], int addr_out[1000], int atanh[12], int sinh[5], int cosh[5]){
    int i;

    // the result is positive or negative
    int is_neg;
    // Input angle
    int beta;
    // Output of the hyperbolic CORDIC block
    int outputcosh, outputsinh;
    // Result of tanh, sinh and cosh
    int result;
    // Token for the repetition of the 4th iteration
    //char token4 = 0;
    // Approximation of cosh(beta) and sinh(beta)

  for (i = 0; i < 1000; i++){
       beta = A[addr_in[i]];

        // Implement approximate range of the hyperbolic CORDIC block
        if (beta >= 20480) {
          result = 4096; // Saturation effect
        } else {
          // An if condition in the loop causes irregular computation.
          // Static scheduler reserves time slot for each iteration
          // causing unnecessary pipeline stalls.
          result = g(beta, atanh, sinh, cosh);
        }

        // Central symmetry correction
        A[addr_out[i]] = result;
  }

}
