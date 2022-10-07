#include <stdio.h>

#define swap(t, x1, x2) \
    {                   \
        t buf;          \
        buf = x1;       \
        x1 = x2;        \
        x2 = buf;       \
    }

int main(int argc, char const *argv[])
{
    float a, b;

    a = 5.2;
    b = 10.3;

    swap(float, a, b);

    printf("%f %f", a, b);
    return 0;
}
