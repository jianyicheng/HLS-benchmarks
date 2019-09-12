/*

  Benchmark:	BNNKernel
  FileName:		g1.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

void g1(int alpha, int in[10000], int i, int w[10000], int addr_in[10000], int data[10000]){
#pragma SS II=1
	
	int j, x, lut;

	for (j=0;j<100;j++){
		x = i*100+j;
		lut=in[x]^w[x];
		data[addr_in[x]] += lut*alpha;
	} 

}
