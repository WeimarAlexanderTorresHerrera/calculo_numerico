#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n=0;
    double xf=1;
    double xi=0;
    double paro=0.000000000000001;
    double xr, fi, fr, ev, er;
    while((xf-xi) > paro)
    {
        n++;
        xr = (xf+xi)/2;
        fi = exp(-xi)-xi;
        fr = exp(-xr)-xr;
        ev = fabs(0.567143290409783 - xr);
        er = ev/0.567143290409783;
        //printf("%d\t%.15lf\t%.15lf\t%.15lf\t%.15lf\t%.15lf\t%.15lf\t%.15lf\n", n, xi, xf, xr, fi, fr, ev, er);
        if((fi*fr)>0)
        {
            xi=xr;
        }
        else
        {
            xf=xr;
        }
    }
    printf("%.15lf\n", xr);
    return 0;
}
