#include <stdio.h>
#include <string.h>
#include "chapter_5.h"

int main(int argc, char const *argv[])
{
    int nlines;
    int numeric = 0, reverse = 0;
    char c;
    // arg processing
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                printf("arg: illegal option%c\n", c);
                argc = 0;
                return -1;
                break;
            }
    // sorting
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        str_qsort((void **)lineptr, 0, nlines - 1, reverse, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input to big to sort\n");
        return 1;
    }
}
