#include "levmarq.h"
#include <stdlib.h>

int main(){
	int ny;
	float dysq[1024];
	int npar;
	float g[128];
	float weight;
	float d[128];
	float y[1024];
	float h[16384];

	ny = 1024;
	npar = 128;
	for (int i = 0; i < 1024; i++){
		dysq[i] = rand();
		y[i] = rand();
	}

	for (int i = 0; i < 128; i++){
		g[i] = rand();
		d[i] = 0.0f;
	}

	for (int i = 0; i < 16384; i++){
		h[i] = 0.0f;
	}

	levmarq(1, ny, dysq,  npar,  g,  d,  y,  h);
	return 0;
}
