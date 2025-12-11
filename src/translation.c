#include "../include/translation.h"
#include <stdlib.h>
#include <string.h>

#define START_LEN 5
#define GROW_SIZE 2

void reverse_string(char* str) {
    if (str == NULL)
        return;

    char* start = str;
    char* end = str + strlen(str) - 1;

    for (;start < end; start++, end--)
    {
        char c = *start;
        *start = *end;
        *end = c;
    }
}

char* _translation(long x, int base)
{
    int cur_size = START_LEN;
    char* res = malloc(sizeof(char) * cur_size);
    if (res == NULL)
        return NULL;
    int i = 0;
    while (x)
    {
        for (; i < cur_size - 1 && x; i++)
        {
            res[i] = (x % base) + '0';
            x /= base;
        }
        if (x)
        {
            char* new_buf = realloc(res, cur_size * GROW_SIZE);
            if (new_buf == NULL)
            {
                free(res);
                return NULL;
            }
            res = new_buf;
        }
    }
    res[i] = '\0';
    reverse_string(res);
    return res;
}