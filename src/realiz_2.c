#include "../include/lib.h"
#include "../include/translation.h"

float E(int x)
{
    float res = 1.0;
    long n_fact = 1;
    for(int n=1; n <= x; n++)
        res += 1.0 / (n_fact *= n);
    return res;
}

char* translation(long x)
{
    return _translation(x, 3);
}
