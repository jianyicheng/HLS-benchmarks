/*

  Benchmark:	gSumIf
  FileName:		g.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

#include "gSumIf.h"

double g(double i){
#pragma SS II =5
      
	if (i > 5)
        return (((((i+0.25)*i+0.5)*i+0.125)*i+0.25)*i+0.5)*i+0.25;
    else
        return (((((i+0.64)*i+0.7)*i+0.21)*i+0.33)*i+0.25)*i+0.125;
  
}
