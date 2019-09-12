/*

  Benchmark:		gSum
  FileName:		g.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

#include "gSum.h"

double g(double i){
#pragma SS II=1

        return (((((i+0.64)*i+0.7)*i+0.21)*i+0.33)*i+0.25)*i+0.125;
}
