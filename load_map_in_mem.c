/*
** EPITECH PROJECT, 2023
** load_map_in_mem.c
** File description:
** load a map into the mem given a filepath and a map struct
*/

#include "./include/my_sokoban.h"

static void fill_map_null_char(map_t *map)
{
    for (int y = 0; y < map->y; y ++) {
        for (int x = 0; x <= map->x ; x ++) {
            map->map[y][x] = '\0';
        }
    }
}

static int load_line_in_mem(int fd, int y, map_t *map)
{
    char buff[1];
    int read_ret = my_read(fd, buff, 1);
    int x = 0;

    if (read_ret == -1)
        return -1;
    while (buff[0] != '\n' && read_ret > 0) {
        map->map[y][x] = buff[0];
        read_ret = my_read(fd, buff, 1);
        x += 1;
    }
    map->map[y][x] = buff[0];
    if (read_ret == -1)
        return -1;
    return read_ret;
}

int load_map_in_mem(char const *filepath, map_t *map)
{
    int fd;
    int read_ret;

    fill_map_null_char(map);
    if (my_open(filepath, &fd) == -1)
        return -1;
    for (int y = 0; map->map[y] != NULL; y ++) {
        read_ret = load_line_in_mem(fd, y, map);
        if ( read_ret == -1)
            return -1;
        if (read_ret == 0)
            return 1;
    }
    if (my_close(fd) == -1)
        return -1;
    return 1;
}
