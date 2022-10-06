#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattren[] = "qwe";

int main()
{
    char line[MAXLINE];
    int index, found = 0;

    while (my_getline(line, MAXLINE) > 0)
        if ((index = strindex(line, pattren)) >= 0)
        {
            printf("%s %d\n", line, index);
            found++;
        }
    return found;
}

int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;

    while (--lim > 0 && (c = getchar()) != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char f[])
{
    int i, j, index;

    index = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = 0; f[j] != '\0' && s[i + j] == f[j]; j++)
            ;
        if (j > 0 && f[j] == '\0')
        {
            index = i;
        }
    }
    return index;
}