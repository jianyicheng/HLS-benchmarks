#include "evalPos.h"


void evalPos(int board[64], int color[1], int profile[1], int rawMoveCount[64], int pm_2[2], float res[1])
{
  float centralityValue = 0.0f;
  int b, benefitMagnitude, moveCount, temp;
  float temp_2;
  int color_ = color[0];
  int profile_ = profile[0];

  for (int i = 0; i < 64; i++)
  {
     b = board[i];
    // Evaluates to -1 or 1, depending on piece/player color
     benefitMagnitude = ((b & 1) ^ color_) * -2 + 1;
     moveCount = rawMoveCount[i];

     temp = (b & 62) >> 1;
     if (temp == 9){
         temp_2 = g(profile_, i, moveCount, benefitMagnitude, pm_2[profile_]);
        centralityValue -= temp_2;//benefitMagnitude * (fmax(fabs(2.5f - i % 6), fabs(2.5f - i / 6))) * pm_2[profile_];
    }
  }

  res[0] = centralityValue;
}

