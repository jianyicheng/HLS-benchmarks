/*

  Benchmark:		getTanhDouble
  FileName:     	inlined.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/

#include "getTanhDouble.h"

void inlined(double A[1000], int addr_in[1000], int addr_out[1000]){
  int i;
  double result, is_neg, beta;

  for (i = 0; i < 1000; i++){
       beta = A[addr_in[i]];

	if (beta >= 1){
	  result = 1.0;
	}
	else{
	  result = ((beta*beta+19.52381)*beta*beta+3.704762)*beta*is_neg;
	}

	A[addr_out[i]] = result;
  }

}
