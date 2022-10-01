#include <stdio.h>
#define MAXLEN 100

int my_getline(char s[], int max_len);
int strindex(char flow[], char sample[]);
int strrindex(char flow[], char sample[]);
char pattern[] = "er";

int main_4_1_strrindex()
{
    char line[MAXLEN];
    while (my_getline(line, MAXLEN))
    {
        printf("%d\n", strrindex(line, pattern));
    }
    return 0;
}

int my_getline(char s[], int max_len)
{
    int c, i;

    s[0] = '\0';

    for (i = 0; i < max_len - 1 && ((c = getchar()) != '\n'); ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';

    return i;
}

int strindex(char flow[], char sample[])
{
    int i, j, k;

    for (i = 0; flow[i] != '\0'; i++)
    {
        for (j = i, k = 0; flow[j] == sample[k] && sample[k] != '\0'; j++, k++)
            ;
        if (k > 0 && sample[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}

int strrindex(char flow[], char sample[])
{
    int i, j, k;
    int pos = -1;

    for (i = 0; flow[i] != '\0'; i++)
    {
        for (j = i, k = 0; flow[j] == sample[k] && sample[k] != '\0'; j++, k++)
            ;
        if (k > 0 && sample[k] == '\0')
        {
            pos = i;
        }
    }
    return pos;
}
