#include <string.h>
#define MAXLEN 100
#define MAXLINES 20

char *lineptr[MAXLINES];

char *alloc(int n);
void afree(char *p);

void my_strcat(char *s, char *t);
int my_strend(char *s, char *t);

// lines
// int readlines(char *line_ptr[], int nlines);
// void writelines(char *line_ptr[], int nlines);

// 1_19_longest_string.c
int my_getline(char s[], int max_len);
// sort
void str_qsort(char *line_ptr[], int left, int right);