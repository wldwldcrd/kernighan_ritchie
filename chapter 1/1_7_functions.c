#include <stdio.h>

int power(int m, int n);

void main() {
    for (int i = 0; i < 10; ++i)
        printf("%6d %6d %6d\n", i, power(2,i), power(-3,i));
}

int power(int base, int n) {
    int res = 1;

    for (int i = 0; i < n; i++) {
        res *= base;
    }
    
    return (res);
}
