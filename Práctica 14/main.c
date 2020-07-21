#include <stdio.h>

void imprimirRespuesta(int f, double res[f]) {
    for (int i = 0; i < f; i++) {
        printf("El valor de x%d es: %f\n", i+1, res[i]);
    }
}

void gaussJordan(int ft, int ct, double sisEc[ft][ct], double aux[ft][ct]) {
  for(int it = 0; it < ft; it++) {
    double den = sisEc[it][it];
    for(int c = it; c < ct; c++) {
      sisEc[it][c] = sisEc[it][c] / den;
    }
    for(int f = 0; f < ft; f++) {
      for(int c = 0; c < ct; c++) {
        aux[f][c] = sisEc[f][c];
      }
    }
    for(int f = 0; f < ft; f++) {
      if(it != f) {
        for(int c = it; c < ct; c++) {
          sisEc[f][c] = aux[f][c]-(aux[it][c]*aux[f][it]);
        }
      }
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
  double res[3];
  double aux[3][4];
  gaussJordan(f, c, sisEc, aux);
  for(int fi = 0; fi < f; fi++) {
    res[fi] = sisEc[fi][c-1];
  }
  imprimirRespuesta(f, res);
}
