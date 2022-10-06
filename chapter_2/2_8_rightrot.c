#include <limits.h>

unsigned int rightrot(unsigned int x, int n)
{
    return (x << (32 - n) | x >> n);
}