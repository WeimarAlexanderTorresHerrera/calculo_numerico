#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("La ecuacion a resolver tiene la forma a*x^2 + b*x + c = 0\n");
    printf("Introduzca a:");
    double a;
    scanf("%lf", &a);
    printf("Introduzca b:");
    double b;
    scanf("%lf", &b);
    printf("Introduzca c:");
    double c;
    scanf("%lf", &c);
    printf("La ecuacion a resolver es: %lf*x^2 + %lf*x + %lf = 0\n", a, b, c);
    double discriminante = b * b - 4 * a * c;
    if (discriminante >= 0) {
        double r1 = (- b + sqrt(discriminante)) / (2 * a);
        printf("La respuesta 1 es: %lf\n", r1);
        double r2 = (- b - sqrt(discriminante)) / (2 * a);
        printf("La respuesta 2 es: %lf", r2);
    }
    else {
        double r = (- b) / (2 * a);
        double i = sqrt(-discriminante) / (2 * a);
        printf("La respuesta 1 es: %lf + %lfi\n", r, i);
        printf("La respuesta 2 es: %lf - %lfi", r, i);
    }
    return 0;
}
