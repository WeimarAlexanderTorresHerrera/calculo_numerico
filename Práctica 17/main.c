#include <stdio.h>

void main() {
  int nDatos = 4;
  double datos[4][2] = {{0, 1}, {1.3862944, 4}, {1.7917595, 6}, {1.6094379, 5}};
  int orden = 3;
  int x = 2;

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
  // Imprimir matriz
  printf("La matriz es:\n");
  for (int i = 0; i < nDatos; i++) {
    printf("{");
    for (int j = 0; j < nDatos - i; j++) {
      printf("  %f  ", matriz[i][j]);
    }
    printf("}\n");
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
  printf("La respuesta es: %.8f\n", res);
}
