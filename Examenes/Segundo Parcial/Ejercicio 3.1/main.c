#include <stdio.h>

void main() {
  int nDatos = 5;
  double datos[5][2] = {{4.75, 1}, {4, 2}, {5.25, 3}, {19.75, 5}, {36, 6}};
  int orden = 4;
  double x = 3.5;

  // Crear la matriz
  double matriz[nDatos][nDatos];
  for (int i = 0; i < nDatos; i++) {
    matriz[i][0] = datos[i][0];
  }
  for (int c = 1; c < nDatos; c++) {
    for (int f = 0; f < nDatos - c; f++) {
      matriz[f][c] = (matriz[f][c - 1] - matriz[f + 1][c - 1]) / (datos[f][1] - datos[f + c][1]);
    }
  }

  // Calculo del valor
  double res = 0;
  for (int i = 0; i <= orden; i++) {
    double aux = 1;
    for (int j = 0; j < i; j++) {
      aux *= x - datos[j][1];
    }
    res += matriz[0][i] * aux;
  }

  // Imprimir respuesta
  printf("La respuesta por polinomios de Newton es: %.8f\n", res);
}
