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
    printf("Introduzca el numero de filas de la matriz A\n");
    int f = -1;
    scanf("%d", &f);
    printf("Introduzca el numero de columnas de la matriz A\n");
    int c1 = -1;
    scanf("%d", &c1);
    printf("Introduzca el numero de columnas de la matriz B\n");
    int c2 = -1;
    scanf("%d", &c2);
    printf("Introducir la matriz A\n");
    int m1[f][c1];
    leerMatriz(f, c1, m1);
    printf("Introducir la matriz B\n");
    int m2[c1][c2];
    leerMatriz(c1, c2, m2);
    int r[f][c2];
    for (int v = 0; v < f; v++)
    {
        for (int h = 0; h < c2; h++)
        {
            r[v][h] = 0;
            for (int i = 0; i < c1; i++) {
                r[v][h] += m1[v][i] * m2[i][h];
            }
        }
    }
    printf("La matriz resultado de A * B es:\n");
    imprimirMatriz(f, c2, r);
    return 0;
}
