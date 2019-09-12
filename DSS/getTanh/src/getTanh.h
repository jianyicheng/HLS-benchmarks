/*

  Benchmark:  getTanh
  FileName:   getTanh.h
  Author:     Jianyi Cheng
  Date:       12 Sep 2019

*/

int g(int beta, int atanh[12], int sinh[5], int cosh[5]);
void getTanh(int A[1000], int addr_in[1000], int addr_out[1000], int atanh[12], int sinh[5], int cosh[5]);
void inlined(int A[1000], int addr_in[1000], int addr_out[1000], int atanh[12], int sinh[5], int cosh[5]);
