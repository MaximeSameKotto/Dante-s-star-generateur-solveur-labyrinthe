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
#include "merge.h"

void fill_nb(int *line, int width)
{
    int i = 0;
    static int nb = 0;

    for (; i < width; i++) {
        if (i % 2 == 0) {
            line[i] = nb;
            nb++;
        }
        else
            line[i] = -1;
    }
    line[i] = -2;
}

void fill_wall(int *line, int width)
{
    int i = 0;

    for (; i < width; i++)
        line[i] = -1;
    line[i] = -2;
}

void modify_last_line(int **map, int width, int height)
{
    int highest_nb = 0;

    if (width % 2 == 0 && height % 2 == 0) {
        highest_nb = map[height - 2][width - 2];
        map[height - 1][width - 1] = highest_nb;
        map[height - 1][width - 2] = highest_nb;
    }
    else if (height % 2 == 0) {
        highest_nb = map[height - 2][width - 1];
        map[height - 1][width - 1] = highest_nb;
    }
    else if (width % 2 == 0) {
        highest_nb = map[height - 1][width - 2];
        map[height - 1][width - 1] = highest_nb;
    }
}

char **perfect_maze(int width, int height)
{
    int **map;
    int i = 0;

    if (width > 200 && height > 200)
        return (basic_maze(width, height));
    map = malloc(sizeof(int *) * (height + 1));
    for (; i < height; i++)
        map[i] = malloc(sizeof(int) * (width + 1));
    map[i] = NULL;
    for (int j = 0; map[j] != NULL; j++) {
        if (j % 2 == 0)
            fill_nb(map[j], width);
        else
            fill_wall(map[j], width);
    }
    modify_last_line(map, width, height);
    return (random_merge_algo(map, width, height));
}

char **imperfect_maze(int width, int height)
{
    char **map;
    static time_t current_time = 0;

    srand(current_time = time(&current_time));
    if (height < 200 && width < 200)
        map = perfect_maze(width, height);
    else
        map = true_random(width, height);
    create_loop(map, height);
    return map;
}
