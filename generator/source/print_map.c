/*
** EPITECH PROJECT, 2020
** dante
** File description:
** print map file
*/

#include <stdlib.h>
#include <stdio.h>

int get_arr_size(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return i;
}

void print_map(char **map)
{
    int arr_size = get_arr_size(map);
    int i = 0;

    for (; i < arr_size - 1; i++)
        printf("%s\n", map[i]);
    printf("%s", map[i]);
}
