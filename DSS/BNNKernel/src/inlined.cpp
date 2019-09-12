/*

  Benchmark:	BNNKernel
  FileName:		inlined.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

#include "bnn.h"

void inlined(int addr_in[10000], int alpha, int w[10000], int addr_out[10000], int data[10000], int in[10000], int mean[10000]){
  int lut, m,i,j,k, x, y, z, temp;

  for (i=0; i<100; i++){
	for (j=0;j<100;j++){
		x = i*100+j;
		lut=in[x]^w[x];
		data[x] += lut*alpha;
	} 

	if (i==99){
		  for(k=0; k<100; k++){
		  y=i*100+k;
		  m=mean[y];
		  temp = data[y];
		  if (temp > 0)
			z = temp -m;
		  else
			z = temp +m;
		  data[y] = z;
		}

	}
  }
}


