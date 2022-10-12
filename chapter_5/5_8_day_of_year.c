#include <stdio.h>
#include <stdlib.h>

// static char daytab[2][13] = {
//     {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//     {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
static char daytab_non_leap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char daytab_leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytab[2] = {daytab_non_leap, daytab_leap};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

int main(int argc, char const *argv[])
{
    int i;
    int month, day;

    // arg printing
    // printf("%d\n", argc);
    // for (i = 0; i < argc; i++)
    // {
    //     printf("a%sa\n", argv[i]);
    // }

    if (argv[1][0] == 'd')
    {
        if (argc < 5)
            printf("Not ehough args for day of year calculation\n");
        else
            printf("Day of year: %d\n", day_of_year(atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
    }
    else
    {
        if (argc < 4)
        {
            printf("Not ehough args for day and month calculation\n");
        }
        else
        {
            month_day(atoi(argv[2]), atoi(argv[3]), &month, &day);
            printf("Month: %s\nDay: %d\n", month_name(month), day);
        }
    }

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int leap, i;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
    {
        day += *(daytab[leap] + i);
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap, i;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= *(daytab[leap] + i);
    }
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"};
    return (n < 1 || n > 12) ? name[0] : name[n];
}