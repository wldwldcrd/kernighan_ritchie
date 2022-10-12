#include <stdio.h>
#define MAXLINE 100

int strindex(char flow[], char sample[]);
int strrindex(char flow[], char sample[]);

int main(int argc, char const *argv[])
{
    int c, reverse = 0, found = 0;
    char *s, *f;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'r':
                reverse = 1;
                break;
            default:
                printf("arg: illegal option%c\n", c);
                argc = 0;
                found = -1;
                break;
            }

    if (argc != 2)
        printf("Usage: use -r s1 s2 pattern\n");
    else
    {
        s = *argv++;
        f = *argv;
        if (reverse)
            found = strrindex(s, f);
        else
            found = strindex(s, f);
    }

    printf("Found = %d\n", found);

    return 0;
}
