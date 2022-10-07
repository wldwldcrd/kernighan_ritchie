#include <stdio.h>
#include "chapter_5.h"

int main(int argc, char const *argv[])
{
    char s[MAXLEN], t[MAXLEN];
    int res;

    scanf("%s", s);
    scanf("%s", t);

    // my_strcat(s, t);
    res = my_strend(s, t);

    printf("Res = %d\n", res);
    return 0;
}
