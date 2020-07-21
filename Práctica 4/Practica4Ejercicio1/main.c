#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 0;
    double p = 0.1;
    double d = 0.00000000000000001;
    double x = 0;
    double r = 0;
    double y, ev, er;
    while(p > d)
    {
        n++;
        y = exp(-x)-x;
        ev = fabs(0.56714329040978384 - x);
        er = ev/0.56714329040978384;
        if(y > 0)
        {
            x += p;
            r = x;
            //printf("%d\t%.17lf\t%.17lf\t%.17lf\t%.17lf\t%.17lf\t\n", n, ev, er, p, x, y);
        }
        else
        {
            x -= p;
            p = p / 10;
            x += p;
            //printf("%d\t%.17lf\t%.17lf\t%.17lf\t%.17lf\t%.17lf\t%.17lf\t\n", n, ev, er, p, x, y, r);
        }
    }
    printf("%.17lf\n", r);
    return 0;
}
