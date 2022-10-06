#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printd(int);
void my_qsort(int v[], int left, int right);

int main()
{
    srand(time(NULL));
    int i;
    int val[10];
    // generate val array
    for (i = 0; i < 10; i++)
    {
        val[i] = rand() % 100;
        printf("%d ", val[i]);
    }
    printf("\n");

    my_qsort(val, 0, 9);

    for (i = 0; i < 10; i++)
    {
        printf("%d ", val[i]);
    }
    printf("\n");

    // printd(12345);

    return 0;
}

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

void my_qsort(int v[], int left, int right)
{
    void my_swap(int v[], int i, int j);

    int i, last;

    if (left >= right)
        return;
    my_swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            my_swap(v, ++last, i);
    my_swap(v, left, last);
    my_qsort(v, left, last - 1);
    my_qsort(v, last + 1, right);
}

void my_swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}