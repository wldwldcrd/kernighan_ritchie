// #include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASH_SIZE 101

static struct nlist *hashtab[HASH_SIZE];

unsigned hash(char *s);

struct nlist *install(char *s, char *t);
struct nlist *lookup(char *s);
void undef(char *s);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASH_SIZE;
};

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np->next != NULL; np = np->next)
        if (!strcmp(s, np->name))
            return np;

    return NULL;
};

struct nlist *install(char *s, char *t)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(s)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(s)) == NULL)
            return NULL;
        hashval = hash(s);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
    {
        free((void *)np->defn);
        if ((np->defn = strdup(s)) == NULL)
            return NULL;
    }
    return np;
};

void undef(char *s)
{
    struct nlist *np;
    struct nlist *np_prev;

    if ((np = lookup(s)) != NULL)
    {
        if (np == hashtab[hash(s)])
        {
            hashtab[hash(s)] = np->next;
        }
        else
        {

            for (np_prev = hashtab[hash(s)]; np_prev->next != NULL; np_prev = np_prev->next)
            {
                if ((np_prev->next) == np)
                {
                    np_prev->next = np->next;
                }
            }
        }
        free(np);
    }
}
