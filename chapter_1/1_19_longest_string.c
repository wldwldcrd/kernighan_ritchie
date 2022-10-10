#include <stdio.h>
#define MAXLEN 100

int my_getline(char s[], int max_len);
void my_copyline(char dest[], char source[]);
void reverse(char s[]);

int print_longest_string()
{

  char c;
  int i, state;
  int act_num, max_num;
  char act_str[MAXLEN], max_str[MAXLEN];

  act_num = max_num = 0;
  act_str[0] = max_str[0] = '\0';

  do
  {
    act_num = my_getline(act_str, MAXLEN);
    if (act_num > max_num)
    {
      max_num = act_num;
      my_copyline(max_str, act_str);
    }
  } while (act_num);

  reverse(max_str);
  printf("Max length:%d\nReversed max string:%s\n", max_num, max_str);
  getchar();

  return (0);
}

int my_getline(char s[], int max_len)
{
  int c, i;

  for (i = 0; i < max_len - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void my_copyline(char dest[], char source[])
{
  int i;

  i = 0;

  while ((dest[i] = source[i]) != '\0')
    i++;
}

void reverse(char s[])
{
  int len, i, c;

  for (len = 0; s[len] != '\0'; len++)
    ;

  // len--;

  for (i = 0; i < len / 2; i++)
  {
    c = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = c;
  }
}