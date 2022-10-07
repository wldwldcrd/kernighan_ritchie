#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0; // stack pointer
double val[MAXVAL];

// push : add f in operands stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack is full, can't push %g\n", f);
}

// pop : get last operand from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("Error: stack empty\n");
        return 0.0;
    }
}