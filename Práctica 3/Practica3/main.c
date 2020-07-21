#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j,i,H[54];
    float k = 0;
    FILE *ent;

    for(i=0; i<54; i++) H[i]=0;

    ent=fopen("HIS3","r");

    for(i=0; i<500; i++) {
      fscanf(ent,"%f",&k);
      for (j=0; j<54; j++) {
          if (-0.25+j*0.01<k && -0.24+j*0.01>k)
          {
              H[j]++;
          }
      }
    }
    fclose(ent);
    for(i=0; i<54; i++) printf("[%f, %f] %d\n", -0.25+i*0.01, -0.24+i*0.01, H[i]);
    return 0;
}
