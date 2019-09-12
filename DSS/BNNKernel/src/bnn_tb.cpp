/*

  Benchmark:    BNNKernel
  FileName:     bnn_tb.cpp
  Author:       Jianyi Cheng
  Date:         12 Sep 2019

*/

#include "bnn.h"

int main(){

  int addr_in[10000], alpha, w[10000], addr_out[10000], data[10000], gold[10000],in[10000], mean[10000];

  for (int i=0; i<10000; i++){
 	addr_in[i] = i;
	addr_out[i] = i;
	in[i] = 1;
	data[i] = 0;
	gold[i] = 0;
	mean[i] = 1;
	w[i] = 1;
  }

  alpha = 2;

  bnn(addr_in, alpha, w, addr_out, data, in, mean);
  inlined(addr_in, alpha, w, addr_out, gold, in, mean); 

  int count = 0;
  for(int i=0;i<10000; i++)
	count += (data[i] == gold[i]);

  if (count == 10000)
	return 0;
  else
	return 1;

}
