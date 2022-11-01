#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "chapter_6.h"

struct tnode *talloc(void);
char *my_strdup(char *);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

int main(int argc, char const *argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != '\n')
        if (isalpha(word[0]))
            root = addtree(root, word);

    treeprint(root);

    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = my_strdup(w);
        p->freq = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->freq++;
    }
    else if (cond > 0)
    {
        p->right = addtree(p->right, w);
    }
    else
    {
        p->left = addtree(p->left, w);
    }
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->freq, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
};

char *my_strdup(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
};