/*
** EPITECH PROJECT, 2020
** dante
** File description:
** maze header
*/

#ifndef MAZE_H
#define MAZE_H

char **perfect_maze(int width, int height);
char **imperfect_maze(int width, int height);
void create_loop(char **map, int height);
int check_paths(int **map);
char **true_random(int width, int height);
char **basic_maze(int width, int height);

#endif
