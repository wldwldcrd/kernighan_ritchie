#include "2_1_limits.c"
#include "2_5_any_char.c"
#include "2_8_rightrot.c"

int main(int argc, char const *argv[])
{
    // print_limits();
    // printf("First similar pos = %d\n", any());

    unsigned int x, n;
    printf("Enter x,n:\n");
    scanf("%x %d", &x, &n);
    printf("%x\n", rightrot(x, n));

    return 0;
}
