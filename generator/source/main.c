/*
** EPITECH PROJECT, 2020
** dante
** File description:
** maze generator main file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "error_handling.h"
#include "maze.h"
#include "print.h"

int main(int ac, char **av)
{
    char **map;

    if (ac == 1 || ac > 4)
        return 84;
    if (check_args(ac, av) == 1)
        return 84;
    if (atoi(av[1]) == 0 || atoi(av[2]) == 0)
        return 84;
    if (ac == 3)
        map = imperfect_maze(atoi(av[1]), atoi(av[2]));
    else
        map = perfect_maze(atoi(av[1]), atoi(av[2]));
    print_map(map);
    return 0;
}
