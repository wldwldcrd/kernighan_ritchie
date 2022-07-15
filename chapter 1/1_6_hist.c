#include <stdio.h>

void main() {
  char c;
  short int i, j, dig_num[10];
  short int max_num, total;
  
  for (i = 0; i < 9; i++)
  {
    dig_num[i] = 0;
  }

  //get data
  total = 0;
  while((c=getchar()) != '\n') {
    total++;
    if ((c >='0') && (c <= '9'))
    {
      dig_num[c-'0']++;
    }
  }
  printf("Total number of digits:%d\n\n", total);

  //max_num find
  max_num = 0;
  for(i=0; i<9; i++) {
    if (dig_num[i]>max_num)
    {
      max_num = dig_num[i];
    }
  }

  //histogramm
  for ( i = 100 ; i >= 1; i-=5)
  {
    printf("%d\t", i);
    for(j=0;j<9;j++) {
      if ((100*dig_num[j]/total)>=i)
      {
        printf("I");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }

  //footer
  printf("n\t");
  for ( i = 0; i < 9; i++) {
    printf("%d",i);
  }
  printf("\n");

  getchar();
}