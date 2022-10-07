int my_strend(char *s, char *t)
{
    char *init_t = t;
    while (*s++)
        ;
    while (*t++)
        ;
    while (*--s == *--t)
        ;
    return (init_t > t);
}