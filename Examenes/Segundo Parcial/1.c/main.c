#include <stdio.h>

void imprimirRespuesta(int f, int c, double res[f][c]) {
    for (int i = 0; i < f; i++) {
      printf("{");
      for (int j = 0; j < c; j++) {
        printf("  %f  ", res[i][j]);
      }
      printf("}\n");
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
  int f = 3;
  int c = 6;
  double sisEc[3][6] = {
    {2, 1, -1, 1, 0 ,0},
    {5, 2, 2, 0, 1, 0},
    {3, 1, 1, 0, 0, 1}
  };
  double res[3][3];
  double aux[3][6];
  gaussJordan(f, c, sisEc, aux);
  for(int fi = 0; fi < f; fi++) {
    for (int ci = c/2; ci < c; ci++) {
      res[fi][ci-3] = sisEc[fi][ci];
    }
  }
  printf("La matriz inversa es:\n");
  imprimirRespuesta(f, c/2, res);
}
