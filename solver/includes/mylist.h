/*
** EPITECH PROJECT, 2020
** mylist
** File description:
** .h
*/

#ifndef MYLIST_H
#define MYLIST_H
#include <stdbool.h>

typedef struct node
{
    bool obstacle;
    bool visited;
    int global_goal;
    int local_goal;
    int x;
    int y;
    int exist;
    struct node *parent;
    struct node *next;
} node_t;

typedef struct ressource
{
    node_t *open;
    node_t *close;
    node_t *actual;
} ressource_t;

#endif
