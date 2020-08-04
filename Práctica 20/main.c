#include <stdio.h>
#include<math.h>

double f(double x, double y) {
  return -2 * pow(x, 3) + 12 * pow(x, 2) - 20 * x + 8.5;
}

void main() {
  FILE * temp[5] = {
    fopen("n1.txt", "w"),
    fopen("n2.txt", "w"),
    fopen("n3.txt", "w"),
    fopen("n4.txt", "w"),
    fopen("n5.txt", "w")
  };
  for (int n = 1; n <= 5; n++) {
    double h = 1 / pow(10, n);
    double xi = 0;
    double yi = 1;
    fprintf(temp[n - 1], "%lf %lf\n", xi, yi);
    while (xi <= 4) {
      double k1 = f(xi, yi);
      double k2 = f(xi + h / 2, yi + h * k1 / 2);
      double k3 = f(xi + h / 2, yi + h * k2 / 2);
      double k4 = f(xi +  h, yi +  h * k3);
      yi = yi + (k1 + (2 * k2) + (2 * k3) + k4) * h / 6;
      xi += h;
      fprintf(temp[n - 1], "%lf %lf\n", xi, yi);
    }
  }

  char * commandsForGnuplot[] = {"set title 'Runge-Kutta'", "set yrange [0:4]", "plot -x*x*x*x/2+4*x*x*x-10*x*x+8.5*x+1 w l, 'n1.txt' w l, 'n2.txt' w l, 'n3.txt' w l, 'n4.txt' w l, 'n5.txt' w l"};
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  for (int i=0; i < 3; i++) {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
  }
}
