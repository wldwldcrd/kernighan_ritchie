#include <stdio.h>
#define MAXLEN 20

void my_strcat(char *, char *);

int main(int argc, char const *argv[])
{
    char s[MAXLEN], t[MAXLEN];
    scanf("%s", s);
    scanf("%s", t);

    my_strcat(s, t);

    printf("%s\n", s);
    return 0;
}

void my_strcat(char *s, char *t)
{
    while (*s)
        *s++;
    while (*t)
        *s++ = *t++;
}