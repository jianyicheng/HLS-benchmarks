#include "levmarq.h"

void levmarq(int dummy, int ny, float dysq[1024], int npar, float g[128], float d[128], float y[1024], float h[16384]){
  for (int x=0; x<ny; x++) {
    float weight = dysq[x]; 
    
    float out0, out1, out2;
    g1(x, &out0, &out1, &out2);

    g[0] = out0;
    g[1] = out1;
    g[2] = out2;
 
    for (int i=0; i<npar; i++) {  // JC: variable loop II
      float x_ = g[i*dummy];
      float k = g2(y[x], x, x_, weight);
      // float k = (y[x] - par[0] + (par[1] - par[0]) * expp(-par[2]*x))*g[i]*weight; 
      d[i] += k;
      for (int j=0; j<=i; j++)
        h[i*128+j] += x_*g[j*dummy]*weight;
    }
  }
}
