/*
** EPITECH PROJECT, 2020
** dante
** File description:
** random_merge_algo file
*/

#include <stdlib.h>

int search_in_line(int *line)
{
    for (int i = 0; line[i] != -2; i++)
        if (line[i] != -1 && line[i] != 0)
            return 1;
    return 0;
}

int check_paths(int **map)
{
    for (int i = 0; map[i] != NULL; i++)
       if (search_in_line(map[i]) == 1)
           return 1;
    return 0;
}
