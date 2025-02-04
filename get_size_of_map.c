/*
** EPITECH PROJECT, 2023
** get_size_of_map.c
** File description:
** finds the size of a map given a filepath and a map_t struct
*/

#include "./include/my_sokoban.h"

static int get_line_lenght(int fd, map_t *map)
{
    int lenght = 0;
    char buff[1];
    int read_ret = my_read(fd, buff, 1);

    while (read_ret > 0) {
        lenght += 1;
        if (lenght > map->x)
            map->x = lenght;
        if (buff[0] == '\n')
            return 1;
        read_ret = my_read(fd, buff, 1);
    }
    return read_ret;
}

int get_size_of_map(char const *filepath, map_t *map)
{
    int fd;
    int is_end_of_file;

    if (my_open(filepath, &fd) == -1)
        return -1;
    is_end_of_file = get_line_lenght(fd, map);
    while (is_end_of_file > 0) {
        map->y += 1;
        is_end_of_file = get_line_lenght(fd, map);
    }
    if (is_end_of_file == -1)
        return -1;
    if (my_close(fd) == -1)
        return -1;
    if (map->y == 0)
        map->y += 1;
    return 0;
}
