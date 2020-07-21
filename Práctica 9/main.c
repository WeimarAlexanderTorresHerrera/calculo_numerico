#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void main() {
  double xv = 0.56714329040978384011;
  bool isFinded = false;
  double xl = 0;
  double xu = 1;
  double fxl = exp(-xl)-xl;
  double fxu = exp(-xu)-xu;
  double xr = xu-(fxu*(xl-xu))/(fxl-fxu);
  double xrant = xr;
  double fxr = exp(-xr)-xr;
  double sig = fxl*fxr;
  double ev = fabs((xv-xr)/xv);
  double er;
  if(sig>0) {
    xl = xr;
  } else if (sig<0) {
    xu = xr;
  } else {
    isFinded = true;
  }
  FILE * temp1 = fopen("data1.txt", "w");
  fprintf(temp1, "%d %.20lf \n", 0, ev);
  FILE * temp2 = fopen("data2.txt", "w");
  for (int i = 1; fabs(xv-xr) > 0.000000000000000000001 && !isFinded; i++) {
    fxl = exp(-xl)-xl;
    fxu = exp(-xu)-xu;
    xr = xu-(fxu*(xl-xu))/(fxl-fxu);
    fxr = exp(-xr)-xr;
    sig = fxl*fxr;
    ev = fabs((xv-xr)/xv);
    er = fabs((xr-xrant)/xr);
    xrant = xr;
    if(sig>0) {
      xl = xr;
    } else if (sig<0) {
      xu = xr;
    } else {
      isFinded = true;
    }
    fprintf(temp1, "%d %.20lf \n", i, ev);
    fprintf(temp2, "%d %.20lf \n", i, er);
  }
  printf("El resultado es: %.20lf\n", xr);
  char * commandsForGnuplot[] = {"set title \"Errores\"", "plot 'data1.txt' w l lw 2 lt 20, 'data2.txt' w l lw 2 lt 10"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 2; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
