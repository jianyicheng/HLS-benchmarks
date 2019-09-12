/*

  Benchmark:		sparseMatrixPower
  FileName:     	smm.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/

#include "smm.h"

void smm(int data[200], int all_zero[100], int w[10000]){
  int j, i, temp;

  for (j=0; j<100; j++){

    temp = all_zero[j];
    if (temp < 10){
    	// An if condition in the loop causes irregular computation.
	    // Static scheduler reserves time slot for each iteration
	    // causing unnecessary pipeline stalls.
    	g(data, j, w);
		// for (i=0; i<100; i++){
		//      data[i+100] += w[i*100+j]*data[i];
		// } 
    }
  }
}
