#include <stdio.h>

int main() {
    int     c = 0;  
    long    nos = 0;

    // while ((c = getchar()) != '\n') {
    //     nos++;
    // }
    for (nos = 0; getchar() != '\n'; nos++)
        ;
    

    printf("Number of symbols = %ld\n", nos);
}