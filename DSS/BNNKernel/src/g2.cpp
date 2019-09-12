/*

  Benchmark:	BNNKernel
  FileName:		g2.cpp
  Author:		Jianyi Cheng
  Date:			12 Sep 2019

*/

void g2(int mean[10000], int i, int addr_out[10000], int data[10000]){
#pragma SS II=1
	
	int temp, m, k, y, z;

		for(k=0; k<100; k++){	
		  y=i*100+k;
		  m=mean[y];
		  temp = data[addr_out[y]];
		  if (temp > 0)
			z = temp -m;
		  else
			z = temp +m;
		  data[addr_out[y]] = z;
		}

}
