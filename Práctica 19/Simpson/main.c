#include <stdio.h>
#include<math.h>

double f(double x) {
  return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double simpson(double cotaInferior, double cotaSuperior, int n) {
  double h = (cotaSuperior - cotaInferior) / n;
  double sumatoriaImpar = 0;
  double sumatoriaPar = 0;
  for (int i = 1; i < n; i++) {
    if (i % 2 == 0) {
      sumatoriaPar += f(cotaInferior + h * i);
    } else {
      sumatoriaImpar += f(cotaInferior + h * i);
    }
  }
  return h * ((f(cotaInferior) + 4 * sumatoriaImpar + 2 * sumatoriaPar + f(cotaSuperior)) / 3);
}

void main() {
  printf("Los resultados son:\n");
  int n[9] = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
  FILE * temp = fopen("errorVerdadero.txt", "w");

  for (int i = 0; i < 9; i++) {
    double integral = simpson(0, 0.8, n[i]);
    printf("Con n = %d la integral es: %f\n", n[i], integral);
    double ev = fabs((1.640533-integral)/1.640533);
    fprintf(temp, "%d %lf\n", n[i], ev);
  }

  char * commandsForGnuplot[] = {"set title 'Errores Verdaderos'", "plot 'errorVerdadero.txt' w l lw 2 lt 20"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 2; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
