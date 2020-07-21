#include <stdio.h>

void main() {
  int datos[5] = {51, 167, 243, 1153, 2187};

  printf("Los numeros multiplos de 3 son:\n");

  for (int i = 0; i < 5; i++) {
    if (datos[i] % 3 == 0) {
      printf("%d\n", datos[i]);
    }
  }
}
