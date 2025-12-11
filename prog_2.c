#include "include/dl_link.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {switching, end} status;

status work(double (*E)(int x), char* (*translation)(long x))
{
    int func, res = 1;
    long x;
    while (1)
    {
        while ((res = scanf("%d", &func)) == 1)
        {
            if (func == 0)
            {
                return switching;
            }

            if ((res = scanf("%ld", &x)) != 1)
                break;

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
    return end;
}

int main()
{
    DLibrary* lib = create_lib();

    status res;
    while ((res = work(lib->E, lib->translation)) != end)
    {
        if (res == switching)
        {
            printf("switched\n");
            switch_lib(lib);
        }
    }

    destroy_lib(lib);
}