// #include "syscall.h"
#include <unistd.h>
#define BUFSIZ 200

int main(int argc, char const *argv[])
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
    {
        write(1, buf, n);
    }

    return 0;
}
