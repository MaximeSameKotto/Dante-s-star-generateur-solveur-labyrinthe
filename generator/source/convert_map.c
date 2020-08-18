/*
** EPITECH PROJECT, 2020
** dante
** File description:
** map converter file
*/

#include <stdlib.h>

void convert_line(int *line, char *converted_line)
{
    for (int i = 0; line[i] != -2; i++) {
        if (line[i] == -1)
            converted_line[i] = 'X';
        else
            converted_line[i] = '*';
    }
}

char **convert_map(int **map, int width, int height)
{
    char **converted_map = malloc(sizeof(char *) * (height + 1));
    int i = 0;

    for (; i < height; i++)
        converted_map[i] = malloc(sizeof(char) * (width + 1));
    converted_map[i] = NULL;
    i = 0;
    for (; map[i] != NULL; i++)
        convert_line(map[i], converted_map[i]);
    return converted_map;
}
