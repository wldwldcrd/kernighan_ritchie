#include <string.h>
#include <stdlib.h>
#include "chapter_5.h"

// void str_swap(char *v[], int i, int j);
// int numcmp(char *, char *);

void str_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void str_swap(void *v[], int i, int j);
    if (left >= right) /* ничего не делать, если в массиве */
        return;        /* меньше двух элементов */
    str_swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            str_swap(v, ++last, i);
    str_swap(v, left, last);
    str_qsort(v, left, last - 1, comp);
    str_qsort(v, last + 1, right, comp);
}

void str_swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
    float v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}