#include <stdio.h>
#include <math.h>

void imprimirRespuesta(int f, double res[f]) {
    for (int i = 0; i < f; i++) {
        printf("El valor de x%d es: %f\n", i+1, res[i]);
    }
}

void gaussSeidel(int f, int c, double sisEc[f][c], double res[f]) {
  while ((fabs(res[0]-3) > 0.000000000000000000001) && (fabs(res[1]+2.5) > 0.000000000000000000001) && (fabs(res[2]-7) > 0.000000000000000000001)) {
    for (int i = 0; i < f; i++) {
      double acc = 0;
      for (int col = 0; col < c-1; col++) {
        if (col != i) {
          acc = acc + res[col]*sisEc[i][col];
        }
      }
      res[i] = (sisEc[i][c-1]-acc)/sisEc[i][i];
    }
  }
}

void main() {
  // [f][c]
  int f = 3;
  int c = 4;
  double sisEc[3][4] = {
    {3, -0.1, -0.2, 7.85},
    {0.1, 7, -0.3, -19.3},
    {0.3, -0.2, 10, 71.4}
  };
  double res[3] = {0, 0, 0};
  gaussSeidel(f, c, sisEc, res);
  imprimirRespuesta(f, res);
}
