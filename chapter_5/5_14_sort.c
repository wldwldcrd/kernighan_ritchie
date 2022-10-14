#include <stdio.h>
#include <string.h>
#include "chapter_5.h"

int main(int argc, char const *argv[])
{
    int nlines;
    int numeric = 0;
    // arg processing
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    // sorting
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        str_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input to big to sort\n");
        return 1;
    }
}
