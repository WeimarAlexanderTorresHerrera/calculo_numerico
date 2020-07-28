#include <stdio.h>
#include <math.h>

void main() {
  double datos[5][2] = {
    {1, 4.75},
    {2, 4},
    {3, 5.25},
    {5, 19.75},
    {6, 36}
  };

  double x = 3.5;
  int n = 5;
  double res = 0;
  for (int x1 = 0; x1 < n; x1++) {
    double aux = 1;
    for (int x2 = 0; x2 < n; x2++) {
      if (x1 != x2) {
        aux *= (x - datos[x2][0]) / (datos[x1][0] - datos[x2][0]);
      }
    }
    res += aux * datos[x1][1];
  }
  printf("La respuesta por polinomios de Lagrange es: %f\n", res);

}
