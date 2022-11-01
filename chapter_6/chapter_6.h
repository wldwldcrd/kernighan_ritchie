// 6_1
#define MAXWORD 100

struct key
{
    char *word;
    int count;
};

int getword(char *, int);

// 6_2
struct tnode
{
    char *word;
    int freq;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *word, int limit)
{
    int c, is_comment;
    char *w = word;

    is_comment = 0;

    while (!isalpha(c = getchar()) && (c != '\n') || is_comment)
    {
        if (c == '\"')
            is_comment = 1 - is_comment;
    };
    *(w++) = c;
    for (; --limit > 0; w++)
    {
        if (!isalpha(*w = getchar()))
        {
            break;
        }
    }
    *w = '\0';
    return word[0];
}