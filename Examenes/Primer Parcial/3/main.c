#include <stdio.h>
#include <math.h>

void main() {
  double xv = 1.9723809981;
  double xi = 1;
  double ev = fabs((xv-xi)/xv);
  FILE * temp1 = fopen("data1.txt", "w");
  fprintf(temp1, "%d %.10lf \n", 0, ev);
  for (int i = 1; fabs(xv-xi) > 0.00000000001; i++) {
    xi = 2*sin(sqrt(xi));
    ev = fabs((xv-xi)/xv);
    fprintf(temp1, "%d %.10lf \n", i, ev);
  }
  printf("El resultado es: %.10lf\n", xi);
  char * commandsForGnuplot[] = {"set title \"Error Verdadero\"", "plot 'data1.txt' w l lw 2 lt 20"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 2; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
