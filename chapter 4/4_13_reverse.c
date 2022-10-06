#include <stdio.h>

#define MAXLEN 20

void my_reverse(char s[], int max);

int main(int argc, char const *argv[])
{
    char s[MAXLEN];
    int i;

    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
        ;
    my_reverse(s, --i);

    printf("%d\n", i);
    printf("%s\n", s);
    return 0;
}

void my_reverse(char s[], int max)
{
    // swap edges
    static char buf;
    buf = s[0];
    s[0] = s[max];
    s[max] = buf;

    if (max > 2)
    {
        my_reverse(s + 1, max - 2);
    }
}