#include "../include/lib.h"
#include "../include/translation.h"
#include <math.h>

double E(int x)
{
    double res = 1.0;
    for(int n=1; n <= x; n++)
        res += pow((1 + 1.0/n), n);
    return res;
}

char* translation(long x)
{
    return _translation(x, 2);
}
