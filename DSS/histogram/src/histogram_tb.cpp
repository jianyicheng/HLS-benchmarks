/*

  Benchmark:		histogram
  FileName:     	histogram_tb.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/

#include "histogram.h"

int main(){
	int f[1000];
	double w[1000], hist[1000];
	
	for(int i = 0; i<1000; i++){

		f[i] = i;
		w[i] = 0.1;
		hist[i] = 0.0;
	}

	histogram(f, w, hist);

	int t = 0;
  	for (int i= 0; i<1000; i++)
		t+=(hist[i]==0.1);

    if (t ==1000)
		return 0;
	else
		return 1;

}
