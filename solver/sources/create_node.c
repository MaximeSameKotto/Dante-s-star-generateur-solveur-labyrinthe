/*
** EPITECH PROJECT, 2020
** create_node
** File description:
** .c
*/

#include "mylist.h"
#include "my.h"
#include <stdlib.h>

int end_distance(int x, int y, map_info_t info)
{
    int counter_x = -1;
    int counter_y = -1;
    int end_distance = 0;

    for (int i = 0; info.map[i] != NULL; i++) {
        for (int j = 0; j != info.line_size; j++)
            counter_x += 1;
        counter_y += 1;
        end_distance = (counter_x + counter_y) - (x + y);
        counter_x = -1;
    }
    return (end_distance * 10);
}

int obstacle_or_not(int x, int y, map_info_t info)
{
    if (info.map[y][x] == 'X')
        return (true);
    return (false);
}

node_t *create_start_node(map_info_t info)
{
    node_t *start = malloc(sizeof(node_t));
    start->x = 0;
    start->y = 0;
    start->global_goal = end_distance(start->x, start->y, info);
    start->local_goal = 0;
    start->obstacle = false;
    start->visited = false;
    start->exist = 0;
    start->parent = NULL;
    start->next = NULL;
    return (start);
}

node_t *create_node(node_t *node, node_t *parent, map_info_t info, int *pos)
{
    node->x = parent->x - pos[0];
    node->y = parent->y - pos[1];
    node->global_goal = end_distance(node->x, node->y, info);
    node->local_goal = (node->x + node->y) * 10;
    node->obstacle = obstacle_or_not(node->x, node->y, info);
    node->visited = false;
    node->exist = 1;
    node->parent =  parent;
    return (node);
}
