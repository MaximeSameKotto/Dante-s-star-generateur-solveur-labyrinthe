/*
** EPITECH PROJECT, 2020
** get_map
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
#include "my_map.h"

int get_line_nb(char *file)
{
    FILE *fd = fopen(file, "r");
    size_t size = 0;
    char *buffer = NULL;
    int line_nb = 1;

    getline(&buffer, &size, fd);
    while (1) {
        buffer = NULL;
        getline(&buffer, &size, fd);
        if (buffer[0] == '\0')
            return (line_nb);
        line_nb += 1;
    }
    return (line_nb);
}

map_info_t get_map(char *file)
{
    FILE *fd = fopen(file, "r");
    map_info_t info;
    size_t size = 0;
    char *buffer = NULL;
    info.line_nb = get_line_nb(file);
    info.map = malloc(sizeof(char *) * (info.line_nb + 1));

    for (int i = 0; 1; i++) {
        buffer = NULL;
        getline(&buffer, &size, fd);
        info.map[i] = malloc(sizeof(char) * (strlen(buffer)));
        info.map[i] = buffer;
        info.map[i][strlen(buffer) - 1] = '\0';
        if (buffer[0] == '\0') {
            info.map[info.line_nb] = NULL;
            return (info);
        }
        info.line_size = strlen(buffer);
    }
}
