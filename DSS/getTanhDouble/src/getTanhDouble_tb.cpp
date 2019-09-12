/*

  Benchmark:		getTanhDouble
  FileName:     	getTanhDouble_tb.cpp
  Author:		    Jianyi Cheng
  Date:			    12 Sep 2019

*/

#include "getTanhDouble.h"
#include <iostream>
#define K 100

int main(){

    double A[1000], gold[1000];
    int addr_out[1000],addr_in[1000];

    for (int i = 0; i < 1000; i++){
        A[i] = i % K == 0? ((double)rand()/RAND_MAX*2.0-1.0): 1.2;
		gold[i] = A[i];
		addr_out[i] = i;
	  	addr_in[i] = i;
    }

    getTanhDouble(A, addr_in, addr_out);

    inlined(gold, addr_in, addr_out);

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
