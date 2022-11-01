#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include "chapter_6.h"

#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key keytab[] = {
    "auto",
    0,
    "break",
    0,
    "case",
    0,
    "char",
    0,
    "const",
    0,
    "continue",
    0,
    "default",
    0,
    "unsigned",
    0,
    "void",
    0,
    "volatile",
    0,
    "while",
    0};

struct key *binsearch(char *, struct key *, int);

int main(int argc, char const *argv[])
{
    struct key *n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != '\n')
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) != NULL)
                n->count++;
    for (n = keytab; n < keytab + NKEYS; n++)
        if (n->count > 0)
            printf("%4d %s\n", n->count, n->word);

    return 0;
}

// search word in tab[0..n-1]
struct key *binsearch(char *word, struct key tab[], int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}