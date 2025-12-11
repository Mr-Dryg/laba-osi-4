#include "../include/lib.h"
#include "../include/translation.h"
#include <math.h>

double E(int x)
{
    return pow((1 + 1.0/x), x);
}

char* translation(long x)
{
    return _translation(x, 2);
}
