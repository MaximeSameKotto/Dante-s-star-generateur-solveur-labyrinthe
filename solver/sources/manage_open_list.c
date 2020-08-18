/*
** EPITECH PROJECT, 2020
** mange_open_list
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

void visited_or_not(node_t *node, node_t *open)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp = open;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (tmp->x == node->x && tmp->y == node->y)
            node->visited = true;
    }
}

node_t *put_open(node_t *n1, node_t *n2, node_t *open, node_t *close)
{
    int counter = 0;

    visited_or_not(n1, open);
    visited_or_not(n2, open);
    if (n1->exist != 0 && n1->obstacle == false && n1->visited == false) {
        n1->next = open;
        counter += 1;
    }
    if (n2->exist != 0 && n2->obstacle == false
            && n2->visited == false && counter == 1) {
        n2->next = n1;
        return (n2);
    }
    if (n2->exist != 0 && n2->obstacle == false
            && n2->visited == false && counter == 0) {
        n2->next = open;
        return (n2);
    }
    if (counter == 1)
        return (n1);
    return (open);
}

node_t *reset_open_list(node_t *open, node_t *actual_point)
{
    while (open != actual_point) {
        open = open->next;
    }
    open->visited = true;
    return (open);
}
