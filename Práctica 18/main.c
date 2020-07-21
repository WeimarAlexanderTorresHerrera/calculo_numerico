#include <stdio.h>
#include <math.h>

void main() {
  double datos[9][2] = {
    {1, 0},
    {4, 1.3862944},
    {6, 1.7917595},
    {5, 1.6094379},
    {3, 1.0986123},
    {7, 1.9459101},
    {8, 2.0794415},
    {9, 2.1972246},
    {10, 2.3025851}
  };

  int x = 2;
  double ev[8];

  for (int n = 2; n < 10; n++) {
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
    ev[n-2] = fabs((0.693147-res)/0.693147);
    printf("La respuesta de orden %d es: %f\n", n - 1, res);
  }

  FILE * temp = fopen("errorVerdadero.txt", "w");
  for (int i = 0; i < 8; i++) {
    fprintf(temp, "%d %lf\n", i + 1, ev[i]);
  }

  char * commandsForGnuplot[] = {"set title 'Errores Verdaderos'", "plot 'errorVerdadero.txt' w l lw 2 lt 20"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 2; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }

}
