#include "evalPos.h"
#include <stdlib.h>

int main(){

	int board[64], color[1], profile[1], rawMoveCount[64], pm_2[2];
	float res[1]; 

	for (int i = 0; i < 64; i++){
		board[i] = (i %2 == 1)?18:1;
	}

	color[0] = 1;
	profile[0] = 0;
	pm_2[0] = 0;
	pm_2[1] = 1;

	evalPos(board, color, profile, rawMoveCount, pm_2, res);

	return 0;
}

