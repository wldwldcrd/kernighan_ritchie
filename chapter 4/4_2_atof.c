#include <ctype.h>

double atoi(char s[])
{
    double val, power, exp_power;
    int i, sign, exp_sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    val = sign * val / power;

    // exp
    if (s[i++] == 'e')
    {
        exp_sign = (s[i++] == '-') ? -1 : 1;
        for (exp_power = 0.0; isdigit(s[i]); i++)
        {
            exp_power = 10.0 * exp_power + (s[i] - '0');
        }
        for (i = 0; i < exp_power; i++)
        {
            if (exp_sign == 1)
            {
                val *= 10.0;
            }
            else
            {
                val /= 10.0;
            }
        }
    }

    return (val);
}
