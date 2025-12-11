#include "include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int func, res = 1;
    long x;
    while (1)
    {
        while ((res = scanf("%d %ld", &func, &x)) == 2)
        {
            if (func == 1)
            {
                double res = E(x);
                printf("%lf\n", res);
            }
            else if (func == 2)
            {
                char* res = translation(x);
                printf("%s\n", res);
                free(res);
            }
            else
                printf("Incorrect input. Correct format: <1 x> or <2 x>\n");
        }
        if (res != EOF)
            printf("Incorrect input. Correct format: <1 x> or <2 x>\n");
        else
            break;
    }
}