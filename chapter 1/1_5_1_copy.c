#include <stdio.h>

int main() {
    int c;

    // print the value of EOF
    printf("%d\n", EOF);

    while ((c = getchar()) != EOF) {

        putchar(c);
    }
}