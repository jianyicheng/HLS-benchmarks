/*

  Benchmark:		sparseMatrixPower
  FileName:     	g.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/

#include "smm.h"

void g(int data[200], int j, int w[10000]){
#pragma SS II=1
  int i;
  for (i=0; i<100; i++){
    data[i+100] += w[i*100+j]*data[i];
  } 
}
