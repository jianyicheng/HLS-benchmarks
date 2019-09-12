/*

  Benchmark:		histogram
  FileName:     	histogram.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/

#include "histogram.h"

void histogram(int f[1000], double w[1000], double hist[1000]) 
{
  for (int i=0; i<1000; ++i) {
	double temp = w[i];
    if (temp >= 0){
		double x = hist[f[i]];
		// An if condition in the loop causes irregular computation.
	    // Static scheduler reserves time slot for each iteration
	    // causing unnecessary pipeline stalls.
		g(f, temp, i, hist, x);
		// hist[f[i]] +=  temp;
	}
  }
}
