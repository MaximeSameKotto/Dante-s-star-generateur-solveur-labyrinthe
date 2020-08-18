/*
** EPITECH PROJECT, 2020
** dante
** File description:
** random_merge_algo file
*/

#include <time.h>
#include <stdlib.h>
#include "maze.h"
#include "merge.h"

void remplace_value(int *line, int subsitute, int replaced)
{
    for (int i = 0; line[i] != -2; i++)
        if (line[i] == replaced)
            line[i] = subsitute;
}

void merge_path(int **map, int p1, int p2)
{
    for (int i = 0; map[i] != NULL; i++)
            (p1 < p2) ? remplace_value(
                    map[i], p1, p2) : remplace_value(map[i], p2, p1);
}

void remove_wall(int **map, int x, int y)
{
    if (y == 0)
        y_equals_0(map, x, y);
    else if (x == 0)
        x_equals_0(map, x, y);
    else
        both_different_of_0(map, x, y);
}

void special_case(int **map, int x, int y)
{
    if (x == 0) {
        if (map[y - 1][x] != -1)
            map[y][x] = map[y - 1][x];
        else if (map[y][x + 1] != -1)
            map[y][x] = map[y][x + 1];
    }
    else {
        if (map[y - 1][x] != -1)
            map[y][x] = map[y - 1][x];
        else if (map[y][x - 1] != -1 && map[y][x + 1] != -1
                && map[y][x - 1] != map[y][x + 1]) {
            map[y][x] = map[y][x - 1];
            merge_path(map, map[y][x - 1], map[y][x + 1]);
        }
    }
}

char **random_merge_algo(int **map, int width, int height)
{
    time_t current_time = 0;
    int x = 0;
    int y = 0;
    char **converted_map;

    srand(current_time = time(&current_time));
    while (check_paths(map) != 0) {
        x = rand() % width;
        y = rand() % height;
        if (map[y][x] == -1 && y != height - 1)
            remove_wall(map, x, y);
        else if (map[y][x] == -1 && y == height - 1)
            special_case(map, x, y);
    }
    return (converted_map = convert_map(map, width, height));
}
