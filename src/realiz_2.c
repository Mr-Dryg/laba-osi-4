#include "../include/lib.h"
#include "../include/translation.h"

double E(int x)
{
    double res = 1.0;
    double n_fact = 1.0;
    for(int n=1; n <= x; n++)
        res += 1.0 / (n_fact *= n);
    return res;
}

char* translation(long x)
{
    return _translation(x, 3);
}
