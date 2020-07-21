#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        int c = i/100;
        int u = i%10;
        if (c==u)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
