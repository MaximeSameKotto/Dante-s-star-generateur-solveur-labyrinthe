/*
** EPITECH PROJECT, 2020
** change_map
** File description:
** .c
*/

#include "my_map.h"
#include "mylist.h"
#include <stdlib.h>
#include <stdio.h>

map_info_t change_map(ressource_t *res, map_info_t info)
{
    info.map[0][0] = 'o';
    while (res->actual->parent != NULL) {
        info.map[res->actual->y][res->actual->x] = 'o';
        res->actual = res->actual->parent;
    }
    return (info);
}

void display_map(map_info_t info)
{
    for (int i = 0; info.map[i] != NULL; i++)
        printf("%s\n", info.map[i]);
}
