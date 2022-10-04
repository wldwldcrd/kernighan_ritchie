#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c, sign;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not value
    i = 0;
    if (isdigit(c) || c == '-') // value
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != '\n')
        ungetch(c);
    return NUMBER;
}
