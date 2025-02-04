/*
** EPITECH PROJECT, 2023
** load_map.c
** File description:
** loads a map in mem given a filepath and a map_t struct
*/

#include "./include/my_sokoban.h"

static void init_map_struct(map_t *map)
{
    map->box_count = 0;
    map->location_count = 0;
    map->player_count = 0;
    map->x = 0;
    map->y = 0;
}

static int alloc_map(map_t *map)
{
    map->map = malloc(sizeof(char *) * (map->y + 1));
    if (map->map == NULL) {
        write(2, "malloc failed(whole map)", 14);
        return -1;
    }
    map->map[map->y] = NULL;
    for (int i = 0; i < map->y; i ++) {
        map->map[i] = malloc(sizeof(char) * (map->x + 1));
        if (map->map[i] == NULL) {
            write(2, "malloc failed(map's line)", 14);
            return -1;
        }
    }
    return 1;
}

int load_map(char const *filepath, map_t *map)
{
    init_map_struct(map);
    if (get_size_of_map(filepath, map) == -1)
        exit(84);
    if (map->x == 0 || map->y == 0)
        exit(84);
    if (alloc_map(map) == -1)
        exit(84);
    if (load_map_in_mem(filepath, map) == -1)
        exit(84);
    if (check_map(map) == -1)
        exit(84);
    return 1;
}
