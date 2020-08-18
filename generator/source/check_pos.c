/*
** EPITECH PROJECT, 2020
** dante
** File description:
** check position file
*/

#include "merge.h"
#include <stdlib.h>

void y_equals_0(int **map, int x, int y)
{
    if (map[y][x - 1] != map[y][x + 1] && map[y][x - 1] != -1 &&
            map[y][x + 1] != -1 && map[y][x + 1] != -2) {
        map[y][x] = map[y][x - 1];
        merge_path(map, map[y][x - 1], map[y][x + 1]);
    }
}

void x_equals_0(int **map, int x, int y)
{
    if (map[y - 1][x] != map[y + 1][x] && map[y - 1][x] != -1 &&
            map[y + 1][x] != -1) {
        map[y][x] = map[y - 1][x];
        merge_path(map, map[y - 1][x], map[y + 1][x]);
    }
}

void both_different_of_0(int **map, int x, int y)
{
    if (map[y - 1][x] != map[y + 1][x] && map[y - 1][x] != -1 &&
            map[y + 1][x] != -1) {
        map[y][x] = map[y - 1][x];
        merge_path(map, map[y - 1][x], map[y + 1][x]);
    }
    else if (map[y][x - 1] != map[y][x + 1] && map[y][x - 1] != -1 &&
            map[y][x + 1] != - 1 && map[y][x + 1] != -2) {
        map[y][x] = map[y][x - 1];
        merge_path(map, map[y][x - 1], map[y][x + 1]);
    }
}
