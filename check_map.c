/*
** EPITECH PROJECT, 2023
** check_map.c
** File description:
** checks if the map is legal or not
*/

#include "./include/my_sokoban.h"

static void setup_player(int x, int y, player_t *player)
{
    player->skin = 'P';
    player->x = x;
    player->y = y;
}

static int count_values(char c, map_t *map, int x, int y)
{
    if (c == 'P') {
        if (map->player_count == 1)
            setup_player(x, y, map->player_2);
        else
            setup_player(x, y, map->player_1);
        map->player_count += 1;
        return 1;
    }
    if (c == 'X') {
        map->box_count += 1;
        return 1;
    }
    if (c == 'O') {
        map->location_count += 1;
        return 1;
    }
    if (c == ' ' || c == '#' || c == '\n')
        return 1;
    write(2, "illegal character found in the map !", 37);
    exit(84);
}

int check_map(map_t *map)
{
    map->box_count = 0;
    map->location_count = 0;
    map->player_count = 0;
    for (int y = 0; map->map[y] != NULL; y ++) {
        for (int x = 0; map->map[y][x] != '\0'; x ++) {
            count_values(map->map[y][x], map, x, y);
        }
    }
    if (map->player_count > 2) {
        write(2, "error:map two player maximum !", 31);
        return -1;
    }
    if (map->location_count < map->box_count) {
        write(2, "error:map not enough locations for the boxes", 45);
        return -1;
    }
    return 0;
}
