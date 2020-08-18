/*
** EPITECH PROJECT, 2020
** dante
** File description:
** maze generator file
*/

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "maze.h"

void fill_first_line(char *line, int width)
{
    int i = 0;

    for (; i < width; i++)
        line[i] = '*';
    line[i] = '\0';
}

void fill_other_line(char *line, int width)
{
    int i = 0;

    for (; i < width - 1; i++)
        line[i] = 'X';
    line[i] = '*';
    line[i + 1] = '\0';
}

char **basic_maze(int width, int height)
{
    char **map = malloc(sizeof(char *) * (height + 1));
    int i = 0;

    for (; i < height; i++)
        map[i] = malloc(sizeof(char) * (width + 1));
    map[i] = NULL;
    for (int j = 0; map[j] != NULL; j++) {
        if (j == 0)
            fill_first_line(map[j], width);
        else
            fill_other_line(map[j], width);
    }
    return map;
}

void make_holes(char *line, int width)
{
    int wall_removed = 0;
    int posi = 0;

    while ((wall_removed = rand() % width) == 0);
    for (int i = 0; i < wall_removed; i++) {
        posi = rand() % width;
        line[posi] = '*';
    }
}

char **true_random(int width, int height)
{
    char **map = basic_maze(width, height);

    for (int i = 1; map[i] != NULL; i++) {
        if (i % 2 == 0)
            make_holes(map[i], width);
        else
            make_holes(map[i], width / 2);
    }
    return map;
}
