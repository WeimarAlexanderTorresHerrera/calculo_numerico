#include <stdio.h>
#include <math.h>

void main() {
  double xv = 0.56714329040978384011;
  double xn = 0;
  double ev = fabs((xv-xn)/xv);
  double er;
  double xnant;
  FILE * temp1 = fopen("data1.txt", "w");
  fprintf(temp1, "%d %.20lf \n", 0, ev);
  FILE * temp2 = fopen("data2.txt", "w");
  for (int i = 1; fabs(xv-xn) > 0.000000000000000000001; i++) {
    xnant = xn;
    xn = exp(-xn);
    ev = fabs((xv-xn)/xv);
    er = fabs((xn-xnant)/xn);
    fprintf(temp1, "%d %.20lf \n", i, ev);
    fprintf(temp2, "%d %.20lf \n", i, er);
  }
  printf("El resultado es: %.20lf\n", xn);
  char * commandsForGnuplot[] = {"set title \"Errores\"", "plot 'data1.txt' w l lw 2 lt 20, 'data2.txt' w l lw 2 lt 10"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 2; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
