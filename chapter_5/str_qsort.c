#include <string.h>
void str_swap(char *v[], int i, int j);

void str_qsort(char *v[], int left, int right)
{
    int i, last;
    void str_swap(char *v[], int i, int j);
    if (left >= right) /* ничего не делать, если в массиве */
        return;        /* меньше двух элементов */
    str_swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            str_swap(v, ++last, i);
    str_swap(v, left, last);
    str_qsort(v, left, last - 1);
    str_qsort(v, last + 1, right);
}

void str_swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}