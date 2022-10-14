#include <stdio.h>
#include "chapter_5.h"

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// int main()
// {
//     int nlines;

//     if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
//     {
//         str_qsort(lineptr, 0, nlines - 1);
//         writelines(lineptr, nlines);
//         return 0;
//     }
//     else
//     {
//         printf("error: intup too big to sort\n");
//         return 1;
//     }
// }

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 1)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}