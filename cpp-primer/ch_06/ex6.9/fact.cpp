#include "chapter6.h"
int fact(int num)
{
    int res = 1; // result
    while (1 < num)
        res *= num--;
    return res;
}