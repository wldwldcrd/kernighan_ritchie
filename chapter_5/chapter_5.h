#include <string.h>
#define MAXLEN 100
#define MAXLINES 20

char *lineptr[MAXLINES];

char *alloc(int n);
void afree(char *p);

void my_strcat(char *s, char *t);
int my_strend(char *s, char *t);

// lines
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// 1_19_longest_string.c
int my_getline(char s[], int max_len);
// sort
void str_qsort(void *line_ptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);