#include "../chapter 1/1_19_longest_string.c"

void expand()
{
    char s1[MAXLEN], s2[MAXLEN];
    int i, j, k;

    my_getline(s1, MAXLEN);

    for (i = 0, k = 0; s1[i] != '\0'; i++)
    {
        if ((s1[i] == '-') && (s1[i - 1] != '-') && (s1[i + 1] != '-') && (i != 0) && (s1[i + 1] != '\0'))
        {
            for (j = s1[i - 1] + 1; j < s1[i + 1]; j++)
            {
                s2[k++] = j;
            }
        }
        else
        {
            s2[k++] = s1[i];
        }
    }

    printf("%s\n", s2);
}