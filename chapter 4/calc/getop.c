#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i;
    static int c = ' ';

    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        i = c;
        c = ' ';
        return i; // not value
    }
    i = 0;
    // sign
    if (c == '-')
    {
        s[++i] = c = getchar();
        if (!isdigit(c))
        {
            return '-';
        }
    }

    if (isdigit(c)) // value
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (i == 0)
    {
        i = c;
        c = ' ';
        return i; // not value
    }

    s[i] = '\0';
    // if (c != '\n')
    //     ungetch(c);
    return NUMBER;
}
