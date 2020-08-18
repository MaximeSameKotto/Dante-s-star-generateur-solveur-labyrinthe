/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** .c
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int check_line(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n')
            return (84);
    return (0);
}

int check_token(char *map)
{
    FILE *fd = fopen(map, "r");
    size_t size = 0;
    char *buffer = NULL;

    if (fd == NULL)
        return (84);
    getline(&buffer, &size, fd);
    while (1) {
        if (check_line(buffer) == 84)
            return (84);
        buffer = NULL;
        getline(&buffer, &size, fd);
        if (buffer[0] == '\0')
            return (0);
    }
    return (0);
}

int error_handling(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (check_token(av[1]) == 84)
        return (84);
    return (0);
}
