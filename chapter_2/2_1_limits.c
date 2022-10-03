#include <stdio.h>
#include <limits.h>

void print_limits()
{
    char c_next, c;
    c = 0;
    for (c_next = -1; c_next < c; c_next--)
        c = c_next;
    printf("Min calc Char = %d\nMax calc Char = %d\n", c, c_next);
    printf("Min lib  Char = %d\nMax lib  Char = %d\n", SCHAR_MIN, SCHAR_MAX);

    int i_next, i;
    i = 0;
    for (i_next = -1; i_next < i; i_next--)
        i = i_next;
    printf("Min calc Int = %d\nMax calc Int = %d\n", i, i_next);
    printf("Min lib  Int = %d\nMax lib  Int = %d\n", INT_MIN, INT_MAX);
}