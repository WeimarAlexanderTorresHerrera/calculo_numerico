#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int f, int c, int m[f][c])
{
    printf("\n");
    for (int v = 0; v < f; v++)
    {
        for (int h = 0; h < c; h++)
        {
            printf("%d     ", m[v][h]);
        }
        printf("\n");
    }
}

int leerMatriz(int f, int c, int m [f][c])
{
    for (int v = 0; v < f; v++)
    {
        for (int h = 0; h < c; h++)
        {
            printf("Introducir el valor de la matriz en [%d, %d]:\n", v, h);
            scanf("%d", &m[v][h]);
        }
    }
    return m;
}

int main()
{
    printf("Introduzca el numero de filas de la matriz\n");
    int f = -1;
    scanf("%d", &f);
    printf("Introduzca el numero de columnas de la matriz\n");
    int c = -1;
    scanf("%d", &c);
    printf("Introducir la matriz A\n");
    int m1[f][c];
    leerMatriz(f, c, m1);
    printf("Introducir la matriz B\n");
    int m2[f][c];
    leerMatriz(f, c, m2);
    int r[f][c];
    for (int v = 0; v < f; v++)
    {
        for (int h = 0; h < c; h++)
        {
            r[v][h] = m1[v][h] + m2[v][h];
        }
    }
    printf("La matriz resultado de A + B es:\n");
    imprimirMatriz(f, c, r);
    return 0;
}
