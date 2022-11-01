#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "chapter_6.h"

struct tnode *talloc(void);
char *my_strdup(char *);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *add_sorted_tree(struct tnode *, struct tnode *);
struct tnode *sort_tree(struct tnode *, struct tnode *);

int main(int argc, char const *argv[])
{
    struct tnode *root;
    struct tnode *sorted_root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != '\n')
        if (isalpha(word[0]))
            root = addtree(root, word);

    printf("Alphabetical:\n");
    treeprint(root);

    sorted_root = sort_tree(sorted_root, root);

    printf("Numerical:\n");
    treeprint(sorted_root);

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

struct tnode *add_sorted_tree(struct tnode *p, struct tnode *new)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = new->word;
        p->freq = new->freq;
        p->left = p->right = NULL;
    }
    else if ((new->freq) < (p->freq))
    {
        p->right = add_sorted_tree(p->right, new);
    }
    else
    {
        p->left = add_sorted_tree(p->left, new);
    }
    return p;
}

struct tnode *sort_tree(struct tnode *sorted, struct tnode *p)
{

    if (p != NULL)
    {
        sorted = sort_tree(sorted, p->left);
        sorted = add_sorted_tree(sorted, p);
        sorted = sort_tree(sorted, p->right);
    }
}