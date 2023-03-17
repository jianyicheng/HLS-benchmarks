#include "los.h"

//------------------------------------------------------------------------
// vectorProcess
//------------------------------------------------------------------------

// SEPARATOR_FOR_MAIN

#include "los.h"
#include <stdlib.h>

#define N 32768

void los(in_int_t obstacles_0[1024], in_int_t obstacles_1[1024],
         in_int_t obstacles_2[1024], in_int_t obstacles_3[1024],
         in_int_t obstacles_4[1024], in_int_t obstacles_5[1024],
         in_int_t obstacles_6[1024], in_int_t obstacles_7[1024],
         out_int_t results_0[1024], out_int_t results_1[1024],
         out_int_t results_2[1024], out_int_t results_3[1024],
         out_int_t results_4[1024], out_int_t results_5[1024],
         out_int_t results_6[1024], out_int_t results_7[1024]) {

loop_0:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_0 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_0[y0 * 64 + x0] == 1)
          sight_0 = 0;
        if ((x0 == 32 && y0 == 32) || sight_0 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }
        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_0 == 1)
        results_0[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_1:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_1 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_1[y0 * 64 + x0] == 1)
          sight_1 = 0;
        if ((x0 == 32 && y0 == 32) || sight_1 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_1 == 1)
        results_1[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_2:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_2 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_2[y0 * 64 + x0] == 1)
          sight_2 = 0;
        if ((x0 == 32 && y0 == 32) || sight_2 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_2 == 1)
        results_2[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_3:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_3 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_3[y0 * 64 + x0] == 1)
          sight_3 = 0;
        if ((x0 == 32 && y0 == 32) || sight_3 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_3 == 1)
        results_3[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_4:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_4 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_4[y0 * 64 + x0] == 1)
          sight_4 = 0;
        if ((x0 == 32 && y0 == 32) || sight_4 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_4 == 1)
        results_4[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_5:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_5 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_5[y0 * 64 + x0] == 1)
          sight_5 = 0;
        if ((x0 == 32 && y0 == 32) || sight_5 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_5 == 1)
        results_5[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_6:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_6 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_6[y0 * 64 + x0] == 1)
          sight_6 = 0;
        if ((x0 == 32 && y0 == 32) || sight_6 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_6 == 1)
        results_6[y_pixel * 64 + x_pixel] = 1;
    }
  }

loop_7:
  for (int y_pixel = 0; y_pixel < 16; y_pixel++) {
    for (int x_pixel = 0; x_pixel < 64; x_pixel++) {
      int sight_7 = 1;
      int x0 = x_pixel;
      int y0 = y_pixel;
      int sx, dx, sy, dy;
      if (x0 < 32) {
        sx = 1;
        dx = 32 - x0;
      } else {
        sx = -1;
        dx = x0 - 32;
      }

      if (y0 < 32) {
        sy = 1;
        dy = 32 - y0;
      } else {
        sy = -1;
        dy = y0 - 32;
      }

      int err = dx - dy;

      while (1) {
        if (!(x0 == 32 && y0 == 32) && obstacles_7[y0 * 64 + x0] == 1)
          sight_7 = 0;
        if ((x0 == 32 && y0 == 32) || sight_7 == 0)
          break;
        int e2 = 2 * err;
        if (e2 > -dy) {
          err = err - dy;
          x0 = x0 + sx;
        }

        if (e2 < dx) {
          err = err + dx;
          y0 = y0 + sy;
        }
      }

      if (sight_7 == 1)
        results_7[y_pixel * 64 + x_pixel] = 1;
    }
  }
}

int main() {
  int obstacles_0[1024], obstacles_1[1024], obstacles_2[1024],
      obstacles_3[1024], obstacles_4[1024], obstacles_5[1024],
      obstacles_6[1024], obstacles_7[1024];
  int results_0[1024], results_1[1024], results_2[1024], results_3[1024],
      results_4[1024], results_5[1024], results_6[1024], results_7[1024];

  srand(9);
  for (int i = 0; i < 1024; i++) {
    obstacles_0[i] = rand() % 2;
    obstacles_1[i] = rand() % 2;
    obstacles_2[i] = rand() % 2;
    obstacles_3[i] = rand() % 2;
    obstacles_4[i] = rand() % 2;
    obstacles_5[i] = rand() % 2;
    obstacles_6[i] = rand() % 2;
    obstacles_7[i] = rand() % 2;
  }

  los(obstacles_0, obstacles_1, obstacles_2, obstacles_3, obstacles_4,
      obstacles_5, obstacles_6, obstacles_7, results_0, results_1, results_2,
      results_3, results_4, results_5, results_6, results_7);

  return 0;
}
