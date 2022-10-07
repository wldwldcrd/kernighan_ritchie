#include <stdio.h>
#include "calc.h"

#define MAXOP 100

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != '\n')
    {
        switch (type)
        {
        case NUMBER:
            op2 = my_atoi(s);
            push(op2);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push((double)((int)pop() % (int)op2));
            break;
        default:
            printf("Error: unknown command %s\n", s);
            break;
        }
    }

    printf("\t%.8g\n", pop());

    return 0;
}