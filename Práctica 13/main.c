#include <stdio.h>

void imprimirRespuesta(int f, double res[f]) {
    for (int i = 0; i < f; i++) {
        printf("El valor de x%d es: %f\n", i+1, res[i]);
    }
}

void eliminacionAdelante(int ft, int ct, double sisEc[ft][ct], double aux[ft][ct]) {
  for(int it = 0; it < (ct-2); it++) {
    for(int f = 0; f < ft; f++) {
      for(int c = 0; c < ct; c++) {
        aux[f][c] = sisEc[f][c];
      }
    }
    for(int f = it+1; f < ft; f++) {
      for(int c = it; c < ct; c++) {
        sisEc[f][c] = aux[f][c]-(aux[it][c]*(aux[f][it]/aux[it][it]));
      }
    }
  }
}

void sustitucionAtras(int ft, int ct, double sisEc[ft][ct], double res[ft]) {
  for(int f = ft-1; f >= 0; f--) {
    double numerador = sisEc[f][ct-1];
    for(int c = ct-2; f < c; c--) {
      numerador -= sisEc[f][c]*res[c];
    }
    res[f] = numerador/sisEc[f][f];
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
  eliminacionAdelante(f, c, sisEc, aux);
  sustitucionAtras(f, c, sisEc, res);
  imprimirRespuesta(f, res);
}
