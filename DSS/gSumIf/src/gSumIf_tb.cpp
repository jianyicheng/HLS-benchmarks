/*

  Benchmark:	gSumIf
  FileName:		gSumIf_tb.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

#include <iostream>
#include "gSumIf.h"
#define K 100

int main(){
    double A[1000], B[1000], accum = 0.0, res, k, i;

    for (int j=0; j<1000; j++)
    {
        A[j] = (double)j+1.0;
	      if (j % K == 0)
	        B[j] = -A[j] + 1.0;
	      else
	        B[j] = -A[j] - 1.0;
        
        i = A[j] + B[j];
	      if (i >= 0){
	        accum += (((((i+0.25)*i+0.5)*i+0.125)*i+0.25)*i+0.5)*i+0.25;
	      }
    }

    res = gSum(A, B);

    if (res == accum)
        return 0;
    else{
	      std::cout << "actual res = " << res << ", gold = " << accum << "\n";
        return 1;
    }
}
