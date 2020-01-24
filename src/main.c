/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for architect
*/
#include "architect.h"

static int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static int str_is_num(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-' || (is_number(str[i + 1]) == 1 &&
            str[i] == '.' && i >= 1 && is_number(str[i - 1]) == 1 ) ||
            is_number(str[i]) == 1)
            continue;
        return 84;
    }
    return 0;
}

static int error_handling(char **av)
{
    if (str_is_num(av[1]) == 84 || str_is_num(av[2]) == 84)
        return 84;
    for (int i = 3; av[i] != NULL; ++i) {
        if ((strcmp(av[i], "-r") == 0 && str_is_num(av[i + 1]) == 0)
            || (strcmp(av[i], "-s") == 0 && str_is_num(av[i + 1]) == 0))
            i += 1;
        else if((strcmp(av[i], "-t") == 0 && str_is_num(av[i + 1]) == 0 &&
                str_is_num(av[i + 2]) == 0)
                || (strcmp(av[i], "-z") == 0 && str_is_num(av[i + 1]) == 0 &&
                    str_is_num(av[i + 2]) == 0))
                i += 2;
        else
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    char **av_2 = av;
    if (ac >= 5 && error_handling(av) == 0)
        return architect(++av_2);
    return 84;
}
