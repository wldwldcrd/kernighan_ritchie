#include <stdio.h>
#include "4_1_strrindex.c"
#include "4_2_atof.c"

int main()
{
    char line[MAXLEN];
    int len;
    // // main_4_1_strrindex();
    my_getline(line, MAXLEN);
    printf("%lf\n", atoi(line));

    return 0;
}