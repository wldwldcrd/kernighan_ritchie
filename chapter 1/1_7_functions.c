#include <stdio.h>

int power();

void main() {
    for (int i = 0; i < 10; ++i)
        printf("%6d %6d %6d\n", i, power(2,i), power(-3,i));
}

int power(int base, int n) {
    int res;

    for (res = 1; n > 0; --n) {
        res *= base;
    }
    
    return (res);
}
