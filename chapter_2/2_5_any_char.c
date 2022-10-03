#include "../chapter 1/1_19_longest_string.c"

int any()
{
    char s1[MAXLEN], s2[MAXLEN];
    int s1_len;
    int i, j;
    // get strings
    my_getline(s1, MAXLEN);
    my_getline(s2, MAXLEN);

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }

    return -1;
}