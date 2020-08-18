/*
** EPITECH PROJECT, 2020
** main
** File description:
** .C
*/

#include "my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return (84);
    solve_maze(av[1]);

    return (0);
}
