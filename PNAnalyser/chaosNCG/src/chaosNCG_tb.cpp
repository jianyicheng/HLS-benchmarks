#include "chaosNCG.h"
#include <stdlib.h>

int main(){
	int I = 10, bo = 900, M[2000], X = 250, Y = 250, params[2], buffer[2000];
	params[0] = 127;
	params[1] = 41;
	for (int i = 0; i < 2000; i++){
		M[i] = rand()%2000;
		buffer[i] = rand()%2000;
	}

	chaosNCG(I, bo, M, X, Y, 127, 41, buffer);
	return 0;
}

