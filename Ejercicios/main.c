#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("s para suma y r para restar\n");
    char f;
    scanf("%s", &f);
    if ('s'==f) {
        int a = 5;
        int b = 1;
        int r = a + b;
        printf("La suma de %d y %d es %d", a, b, r);
    }
    else if ('r'==f) {
        int a = 5;
        int b = 1;
        int r = a - b;
        printf("La resta de %d y %d es %d", a, b, r);
    }
    else {
        printf("Incorrecto");
    }
    return 0;
}

int suma(int a, int b)
{
    int r = a + b;
    return r;
}
