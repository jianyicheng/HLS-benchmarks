/*

  Benchmark:      sparseMatrixPower
  FileName:       smm_tb.cpp
  Author:         Jianyi Cheng
  Date:           12 Sep 2019

*/

#include "smm.h"
#include <iostream>

int main(){
  int data[200], az[100], w[10000], data1[200];
  int temp;

  for(int i=0; i<100; i++){
    data[i] = 1;
    data[i+100] = 0;
    az[i] = i%5;
  }

  for(int i=0; i<10000; i++){
    w[i] = i%10;
  }

  smm(data, az, w);

  for (int j=0; j<100; j++){
    temp = az[j];
    if (temp != 1){
      for (int i=0; i<100; i++){
        data1[i+100] += w[i*100+j]*data[i];
      } 
    }
  }

  int res = 0;
  for(int i = 0; i< 200; i++)
    res += (data[i] == data1[i]);

  if (res = 200)
    return 0;
  else {
    std::cout << res << "\n";
    return 1;
  }

}
