/*
** EPITECH PROJECT, 2020
** change_map
** File description:
** .c
*/

#include "my_map.h"
#include "mylist.h"
#include <stdlib.h>

map_info_t change_map(ressource_t *res, map_info_t info)
{
    while (res->actual_point->parent != NULL) {
        info.map[res->actual_point->y][res->actual_point->x] = 'o';
        res->actual_point = res->actual_point->parent;
    }
    return (info);
}
