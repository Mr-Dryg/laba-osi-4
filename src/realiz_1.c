#include "../include/lib.h"
#include "../include/translation.h"

float E(int x)
{
    return (1 + 1/x) ^ x;
}

char* translation(long x)
{
    return _translation(x, 2);
}
