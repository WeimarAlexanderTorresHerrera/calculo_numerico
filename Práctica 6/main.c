#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("Introduzca la cantidad de numeros a ordenar:\n");
    int n;
    scanf("%d", &n);
    printf("Introduzca los numeros:\n");
    int a[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("[ ");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
    for (int i=1; i<n; i++) {
        int var=a[i];
        bool x = true;
        for (int j=i-1; j>=0 && x; j--) {
            if (var<a[j]) {
                a[j+1]=a[j];
                a[j]=var;
            } else {
                x = false;
            }
        }
    }
    printf("[ ");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
    return 0;
}
