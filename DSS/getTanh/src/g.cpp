/*

  Benchmark:  getTanh
  FileName:   g.cpp
  Author:     Jianyi Cheng
  Date:       12 Sep 2019

*/

#include "getTanh.h"

int g(int beta, int atanh[12], int sinh[5], int cosh[5]){
#pragma SS II=1 

    int x = 0x1351;
    int y = 0;
    int x_new;
    int j, k;
    int index_trigo;
    int result, result_cosh, result_sinh;
    int outputcosh, outputsinh;
	
        if (beta >= 8192) {
            index_trigo = 4;
          } else if (beta >= 12288) {
            index_trigo = 3;
          } else if (beta >= 8192) {
            index_trigo = 2;
          } else if (beta >= 4096) {
            index_trigo = 1;
          } else {
            index_trigo = 0;
          }
          beta = beta - index_trigo * 4096;
          // Call to the hyperbolic CORDIC block
          x = 0x1351;
          y = 0;
          fp_hyp_cordic:
          for (k = 1; k <= 12; k++) {
            // force the 3k+1 th iteration to be repeated
            if (((k%3)==1) &&( k!=1 )){
              for (j=1;j<=2;j++){
              // beta<0 anti-clockwise rotation
                if (beta < 0) {
                  x_new = x - (y >> k);
                  y -= x >> k;
                  beta += atanh[k - 1];
                }
                // beta>0 clockwise rotation
                else {
                  x_new = x + (y >> k);
                  y += (x >> k);
                  beta -= atanh[k - 1];
                }
                x = x_new;
              }
            }
            else {
              if (beta < 0) {
                x_new = x - (y >> k);
                y -= x >> k;
                beta += atanh[k - 1];
              }
              // beta>0 clockwise rotation
              else {
                x_new = x + (y >> k);
                y += (x >> k);
                beta -= atanh[k - 1];
              }
              x = x_new;
            }
          }
          outputcosh = x;
          outputsinh = y;

          // Trigonometric rules application
          result_cosh = (sinh[index_trigo] * outputcosh + cosh[index_trigo] * outputsinh);
          result_sinh = (cosh[index_trigo] * outputcosh + sinh[index_trigo] * outputsinh) >> 12;
          result = result_cosh / result_sinh;
          return result;
}
