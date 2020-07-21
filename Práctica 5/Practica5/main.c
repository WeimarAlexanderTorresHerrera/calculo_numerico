#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long factorial(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    else
    {
        return factorial(n-1)*n;
    }
}

int main()
{
    int m, n;
    double x, r, d, v;
    printf("Introducir el numero de decimales:\n");
    scanf("%d", &m);
    printf("Introducir el numero x:\n");
    scanf("%lf", &x);
    r = exp(-x);
    d = pow(10, -m);
    x = -x;
    v = 0;
    n = 0;
    while(fabs(r - v) > d) {
        v += pow(x, n) / factorial(n);
        n++;
    }
    printf("Solucion: %d\n", n);
    return 0;
}
