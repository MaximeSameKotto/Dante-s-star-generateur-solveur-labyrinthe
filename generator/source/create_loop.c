/*
** EPITECH PROJECT, 2020
** dante
** File description:
** maze generator file
*/

#include <stdlib.h>

void check_wall_surrounding(char **map, int x, int y)
{
    if (map[y][x + 1] == '*' && map[y][x - 1] == '*'
            && (map[y - 1][x - 1] != '*' || map[y - 1][x + 1] != '*' ||
                map[y + 1][x - 1] != '*' || map[y + 1][x + 1] != '*'))
        map[y][x] = '*';
    else if (map[y - 1][x] == '*' && map[y + 1][x] == '*' &&
            (map[y - 1][x - 1] != '*' || map[y - 1][x + 1] != '*' ||
                map[y + 1][x - 1] != '*' || map[y + 1][x + 1] != '*'))
            map[y][x] = '*';
}

void check_line(char **map, int n)
{
    for (int i = 0; map[n][i] != '\0'; i++) {
        if (map[n][i] == 'X' && i != 0)
            check_wall_surrounding(map, i, n);
    }
}

void create_loop(char **map, int height)
{
    for (int i = 1; i < height - 1; i++)
        check_line(map, i);
}
