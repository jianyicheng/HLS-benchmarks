/*

  Benchmark:  getTanh
  FileName:   getTanh_tb.cpp
  Author:     Jianyi Cheng
  Date:       12 Sep 2019

*/


#include "getTanh.h"
#include <iostream>
#define K 100

int main(){

    int atanh[12] = { 0x08C9, 0x0416, 0x0202, 0x0100, 0x0080, 0x0064, 0x0032, 0x0010, 0x0008, 0x0004, 0x0002, 0x0001 };
    int cosh[5] = { 0x1000, 0x18B0, 0x3C31, 0xA115, 0x1B4EE};
    int sinh[5] = { 0x0, 0x12CD, 0x3A07, 0xA049, 0x1B4A3};

    int A[1000],addr_out[1000],addr_in[1000], gold[1000];

    for (int i = 0; i < 1000; i++){
        A[i] = 30000;//i % K == 0? rand()%1000 : 30000;
	gold[i] = A[i];
	addr_out[i] = i;
  	addr_in[i] = i;
    }

    getTanh(A, addr_in, addr_out, atanh, sinh, cosh);

    inlined(gold, addr_in, addr_out, atanh, sinh, cosh);

    int results = 0;
    for (int i = 0; i < 1000; i++)
	results += (gold[i] == A[i]);

        if (results == 1000)
                return 0;
        else{
                std::cout << results << "\n";
                return results;
        }

    
}
