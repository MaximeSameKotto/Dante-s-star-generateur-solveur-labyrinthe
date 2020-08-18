/*
** EPITECH PROJECT, 2020
** solver
** File description:
** .c
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include <string.h>
#include <unistd.h>
#include "mylist.h"
#include "my_map.h"

node_t *best_moove(node_t *open, node_t *actual, map_info_t info)
{
    actual = create_start_node(info);
    node_t *tmp = malloc(sizeof(node_t));
    node_t *tmp2 = malloc(sizeof(node_t));
    tmp = open;
    tmp2 = open;
    while (tmp->next != NULL) {
        if (tmp->global_goal < actual->global_goal && tmp->visited == false) {
            tmp->visited = true;
            actual = open;
        }
        tmp = tmp->next;
    }
    while (open != actual)
        open = open->next;
    open = actual->next;
    //open = tmp2;
    actual->visited = true;
    return (actual);
}

node_t *check_node(node_t *node, map_info_t info, int x, int y)
{
    node_t *neighbour = malloc(sizeof(node_t));
    int *position = malloc(sizeof(int) * 2);
    position[0] = x;
    position[1] = y;

    if (x == 0 && y == 1)
        neighbour = create_node(neighbour, node, info, position);
    if (x == 1 && y == 0)
        neighbour = create_node(neighbour, node, info, position);
    if (x == -1 && y == 0)
        neighbour = create_node(neighbour, node, info, position);
    if (x == 0 && y == -1)
        neighbour = create_node(neighbour, node, info, position);
    return (neighbour);
}

node_t *check_neighbour(ressource_t *res, map_info_t info)
{
    node_t *up = create_start_node(info);
    node_t *left = create_start_node(info);
    node_t *right = create_start_node(info);
    node_t *down = create_start_node(info);
    node_t *tmp = create_start_node(info);

    while (res->actual->global_goal != 0) {
        if (res->actual->y != 0)
            up = check_node(res->actual, info, 0, 1);
        if (res->actual->x != 0)
            left = check_node(res->actual, info, 1, 0);
        if (res->actual->x != info.line_size - 1)
            right = check_node(res->actual, info, -1, 0);
        if (res->actual->y != info.line_nb - 1)
            down = check_node(res->actual, info, 0, -1);
        res->open = put_open(up, down, res->open, res->close);
        res->open = put_open(left, right, res->open, res->close);
        res->actual = best_moove(res->open, res->actual, info);
        res->open = reset_open_list(res->open, res->actual);
    }
}

void solve_maze(char *file)
{
    map_info_t info = get_map(file);
    ressource_t *res = malloc(sizeof(ressource_t));
    res->actual = create_start_node(info);
    res->open = create_start_node(info);
    res->close = create_start_node(info);

    check_neighbour(res, info);
    info = change_map(res, info);
    display_map(info);
}
