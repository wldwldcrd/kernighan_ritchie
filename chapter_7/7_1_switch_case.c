#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int c;

    if (argc == 2 && argv[argc - 1][0] == 'l')
    {
        while ((c = getchar()) != '\n')
        {
            putchar(tolower(c));
        }
    }
    else
    {
        while ((c = getchar()) != '\n')
        {
            putchar(toupper(c));
        }
    }
    putchar(c);

    return 0;
}
