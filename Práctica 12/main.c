#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void tanteo() {
  int n = 0;
  double p = 0.1;
  double d = 0.00000000000000001;
  double x = 0;
  double r = 0;
  double y, ev, er, xant;
  ev = fabs((0.56714329040978384011-x)/0.56714329040978384011);
  FILE * temp1 = fopen("dataTanteo1.txt", "w");
  fprintf(temp1, "%d %.21lf \n", 0, ev);
  FILE * temp2 = fopen("dataTanteo2.txt", "w");
  while(p > d)
  {
      n++;
      y = exp(-x)-x;
      xant = x;
      if(y > 0)
      {
          x += p;
          r = x;
      }
      else
      {
          x -= p;
          p = p / 10;
          x += p;
      }
      ev = fabs((0.56714329040978384011-x)/0.56714329040978384011);
      er = fabs((x-xant)/x);
      fprintf(temp1, "%d %.21lf \n", n, ev);
      fprintf(temp2, "%d %.21lf \n", n, er);
  }
}

void biseccion() {
  int n=0;
  double xf=1;
  double xi=0;
  double paro=0.000000000000001;
  double xr, fi, fr, ev, er, xant;
  xr = (xf+xi)/2;
  fi = exp(-xi)-xi;
  fr = exp(-xr)-xr;
  if((fi*fr)>0)
  {
      xi=xr;
  }
  else
  {
      xf=xr;
  }
  ev = fabs((0.56714329040978384011-xr)/0.56714329040978384011);
  FILE * temp1 = fopen("dataBiseccion1.txt", "w");
  fprintf(temp1, "%d %.21lf \n", 0, ev);
  FILE * temp2 = fopen("dataBiseccion2.txt", "w");
  while((xf-xi) > paro)
  {
      n++;
      xant = xr;
      xr = (xf+xi)/2;
      fi = exp(-xi)-xi;
      fr = exp(-xr)-xr;
      ev = fabs((0.56714329040978384011-xr)/0.56714329040978384011);
      er = fabs((xr-xant)/xr);
      if((fi*fr)>0)
      {
          xi=xr;
      }
      else
      {
          xf=xr;
      }
      fprintf(temp1, "%d %.21lf \n", n, ev);
      fprintf(temp2, "%d %.21lf \n", n, er);
  }
}

void reglaFalsa() {
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
  FILE * temp1 = fopen("dataReglaFalsa1.txt", "w");
  fprintf(temp1, "%d %.21lf \n", 0, ev);
  FILE * temp2 = fopen("dataReglaFalsa2.txt", "w");
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
    fprintf(temp1, "%d %.21lf \n", i, ev);
    fprintf(temp2, "%d %.21lf \n", i, er);
  }
}

void puntoFijo() {
  double xv = 0.56714329040978384011;
  double xn = 0;
  double ev = fabs((xv-xn)/xv);
  double er;
  double xnant;
  FILE * temp1 = fopen("dataPuntoFijo1.txt", "w");
  fprintf(temp1, "%d %.21lf \n", 0, ev);
  FILE * temp2 = fopen("dataPuntoFijo2.txt", "w");
  for (int i = 1; fabs(xv-xn) > 0.000000000000000000001; i++) {
    xnant = xn;
    xn = exp(-xn);
    ev = fabs((xv-xn)/xv);
    er = fabs((xn-xnant)/xn);
    fprintf(temp1, "%d %.21lf \n", i, ev);
    fprintf(temp2, "%d %.21lf \n", i, er);
  }
}

void newtonRaphson() {
  double xv = 0.56714329040978384011;
  double xn = 0;
  double ev = fabs((xv-xn)/xv);
  double er;
  double xnant;
  FILE * temp1 = fopen("dataNewtonRaphson1.txt", "w");
  fprintf(temp1, "%d %.21lf \n", 0, ev);
  FILE * temp2 = fopen("dataNewtonRaphson2.txt", "w");
  for (int i = 1; fabs(xv-xn) > 0.000000000000000000001; i++) {
    xnant = xn;
    xn = xn-(exp(-xn)-xn)/(-exp(-xn)-1);
    ev = fabs((xv-xn)/xv);
    er = fabs((xn-xnant)/xn);
    fprintf(temp1, "%d %.21lf \n", i, ev);
    fprintf(temp2, "%d %.21lf \n", i, er);
  }
}

void secante() {
  double xv = 0.56714329040978384011;
  double xn0 = 0;
  double xn1 = 1;
  double xn2 = xn1-(((exp(-xn1)-xn1)*(xn0-xn1))/((exp(-xn0)-xn0)-(exp(-xn1)-xn1)));
  double ev = fabs((xv-xn2)/xv);
  double er;
  FILE * temp1 = fopen("dataSecante1.txt", "w");
  fprintf(temp1, "%d %.21lf \n", 0, ev);
  FILE * temp2 = fopen("dataSecante2.txt", "w");
  for (int i = 1; fabs(xv-xn2) > 0.000000000000000000001; i++) {
    xn0 = xn1;
    xn1 = xn2;
    xn2 = xn1-(((exp(-xn1)-xn1)*(xn0-xn1))/((exp(-xn0)-xn0)-(exp(-xn1)-xn1)));
    ev = fabs((xv-xn2)/xv);
    er = fabs((xn2-xn1)/xn2);
    fprintf(temp1, "%d %.21lf \n", i, ev);
    fprintf(temp2, "%d %.21lf \n", i, er);
  }
  printf("El resultado del secante es: %.20lf\n", xn2);
}

void main() {
  tanteo();
  biseccion();
  reglaFalsa();
  puntoFijo();
  newtonRaphson();
  secante();

  char * commandsForGnuplot[] = {"set multiplot", "set size .5,.5", "set origin 0.25,.5", "set title 'Errores Secante'",
                                "plot 'dataSecante1.txt' w l lw 2 lt 20, 'dataSecante2.txt' w l lw 2 lt 10", "set origin 0,0",
                                "set title 'Errores Verdaderos'", "plot 'dataTanteo1.txt' w l lw 2 lt 20, 'dataBiseccion1.txt' w l lw 2 lt 10, 'dataReglaFalsa1.txt' w l lw 2 lt 5, 'dataPuntoFijo1.txt' w l lw 2 lt 15, 'dataNewtonRaphson1.txt' w l lw 2 lt 3, 'dataSecante1.txt' w l lw 2 lt 13",
                                "set origin .5,0", "set title 'Errores Relativos'", "plot 'dataTanteo2.txt' w l lw 2 lt 20, 'dataBiseccion2.txt' w l lw 2 lt 10, 'dataReglaFalsa2.txt' w l lw 2 lt 5, 'dataPuntoFijo2.txt' w l lw 2 lt 15, 'dataNewtonRaphson2.txt' w l lw 2 lt 3, 'dataSecante2.txt' w l lw 2 lt 13",
                                "unset multiplot"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 12; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
