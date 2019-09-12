/*

  Benchmark:	BNNKernel
  FileName:		bnn.h
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

void bnn(int addr_in[10000], int alpha, int w[10000], int addr_out[10000], int data[10000], int in[10000], int mean[10000]);
void inlined(int addr_in[10000], int alpha, int w[10000], int addr_out[10000], int data[10000], int in[10000], int mean[10000]);
void g1(int alpha, int in[10000], int i, int w[10000], int addr_in[10000], int data[10000]);
void g2(int mean[10000], int i, int addr_out[10000], int data[10000]);
