#include <stdio.h>

#define in  1
#define out 0

void reverse(char *str, int length);

int print_longest_string() {
  
  char c;
  int i, state;
  int  act_num, max_num;
  char act_wrd[20], max_wrd[20];

  act_num = max_num = 0;
  act_wrd[0] = max_wrd[0] = '\0';
  do {
    c=getchar();
    if ((c == ' ') || (c=='\n'))
    {
      act_wrd[act_num] = '\0';
      if (act_num > max_num)
      {
        max_num = act_num;
        for (i = 0; i <= act_num; i++)
        {
          max_wrd[i] = act_wrd[i];
        }
      }
      act_num = 0;
      state = out;
    }
    else {
      act_wrd[act_num] = c;
      act_num++;
      state = in;
    }
  } while (c != '\n');

  reverse(max_wrd, max_num);
  if (max_num>0)
  {
    printf("%s\n", max_wrd);
  }

  getchar();
  return(0);
}

разобраться в формате строк и разбить программу на функции

void reverse(char *str, int length) {

  int i;
  char buf;

  i = length/2;
  length--;
  while(i--) {
    buf = str[i];
    str[i] = str[length-i];
    str[length-i] = buf;
  }
}