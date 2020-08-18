/*
** EPITECH PROJECT, 2020
** my
** File description:
** .h
*/

#ifndef MY_H
#define MY_H
#include "my_map.h"
#include "mylist.h"

//error handling:
int error_handling(int ac, char **av);
int check_token(char *map);
int check_line(char *buffer);
//get map
map_info_t get_map(char *file);
int get_line_nb(char *file);
//create a node
node_t *create_start_node(map_info_t info);
node_t *create_node(node_t *node, node_t *parent, map_info_t info, int *pos);
int obstacle_or_not(int x, int y, map_info_t info);
int end_distance(int x, int y, map_info_t info);
//change_map
map_info_t change_map(ressource_t *res, map_info_t info);
//display map
void display_map(map_info_t info);
//manage_open_list
void visited_or_not(node_t *node, node_t *close);
node_t *put_open(node_t *node_1, node_t *node_2, node_t *open, node_t *close);
node_t *reset_open_list(node_t *open, node_t *actual_point);
//resolve_maze
void solve_maze(char *file);

#endif
