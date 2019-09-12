/*

  Benchmark:	BNNKernel
  FileName:		bnn.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

#include "bnn.h"

void bnn(int addr_in[10000],int alpha, int w[10000], int addr_out[10000], int data[10000], int in[10000], int mean[10000]){

  int lut, m,i,j,k, x, y, z, temp;

  for (i=0; i<100; i++){
  	g1(alpha, in, i, w, addr_in, data);
	// for (j=0;j<100;j++){
	// 	x = i*100+j;
	// 	lut=in[x]^w[x];
	// 	data[addr_in[x]] += lut*alpha;
	// } 

  	if (i == 99){
  		// An if condition in the loop causes irregular computation.
	    // Static scheduler reserves time slot for each iteration
	    // causing unnecessary pipeline stalls.
  		g2(mean, i, addr_out, data);
		// for(k=0; k<100; k++){
		//   y=i*100+k;
		//   m=mean[y];
		//   temp = data[addr_out[y]];
		//   if (temp > 0)
		// 	z = temp -m;
		//   else
		// 	z = temp +m;
		//   data[addr_out[y]] = z;
		// }
  	 
	}
  }
}
