/*

  Benchmark:		histogram
  FileName:     	g.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/


#include "histogram.h"

void g(int f[1000], double temp, int i, double hist[1000], double x){
#pragma SS II=1

	hist[f[i]] = x+ temp;
}
