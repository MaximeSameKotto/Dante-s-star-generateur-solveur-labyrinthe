/*
** EPITECH PROJECT, 2020
** dante
** File description:
** merge header
*/

#ifndef MERGE_H
#define MERGE_H

void y_equals_0(int **map, int x, int y);
void x_equals_0(int **map, int x, int y);
void both_different_of_0(int **map, int x, int y);
void merge_path(int **map, int p1, int p2);
char **convert_map(int **map, int width, int height);
char **random_merge_algo(int **map, int width, int height);

#endif
