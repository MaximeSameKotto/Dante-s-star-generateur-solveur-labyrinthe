/*
** EPITECH PROJECT, 2020
** dante
** File description:
** maze generator main file
*/

#include <string.h>

int check_num(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (arg[i] < '0' || arg[i] > '9')
            return 1;
    return 0;
}

int check_args(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (check_num(av[i]) == 1 && i < 3)
            return 1;
        if (i == 3 && strcmp("perfect", av[i]) != 0)
            return 1;
    }
    return 0;
}
