#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void main() {
  double xv = 3.1622776602;
  bool isFinded = false;
  double xl = 3;
  double xu = 4;
  double fxl = xl-sqrt(10);
  double fxu = xu-sqrt(10);
  double xr = xu-(fxu*(xl-xu))/(fxl-fxu);
  double fxr = xr-sqrt(10);
  double sig = fxl*fxr;
  double ev = fabs((xv-xr)/xv);
  if(sig>0) {
    xl = xr;
  } else if (sig<0) {
    xu = xr;
  } else {
    isFinded = true;
  }
  FILE * temp1 = fopen("data1.txt", "w");
  fprintf(temp1, "%d %.10lf \n", 0, 0);
  fprintf(temp1, "%d %.10lf \n", 1, ev);
  for (int i = 1; fabs(xv-xr) > 0.00000000001 && !isFinded; i++) {
    fxl = xl-sqrt(10);
    fxu = xu-sqrt(10);
    xr = xu-(fxu*(xl-xu))/(fxl-fxu);
    fxr = xr-sqrt(10);
    sig = fxl*fxr;
    ev = fabs((xv-xr)/xv);
    if(sig>0) {
      xl = xr;
    } else if (sig<0) {
      xu = xr;
    } else {
      isFinded = true;
    }
    fprintf(temp1, "%d %.10lf \n", i, ev);
  }
  printf("El resultado es: %.10lf\n", xr);
  // Como se resuelve a la primera no se necesita un grafico y se añade un valor para que la grafica no de errores
  char * commandsForGnuplot[] = {"set title \"Error Verdadero\"", "plot 'data1.txt' w l lw 2 lt 20"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 2; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
