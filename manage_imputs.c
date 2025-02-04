/*
** EPITECH PROJECT, 2023
** manage_imputs.c
** File description:
** manages player imputs
*/

#include "include/my_sokoban.h"

static void move_player_one(map_t *map, int ch)
{
    switch (ch) {
        case 0403:
            move_player_card(map, map->player_1, 0, -1);
            break;
        case 0402:
            move_player_card(map, map->player_1, 0, 1);
            break;
        case 0405:
            move_player_card(map, map->player_1, 1, 0);
            break;
        case 0404:
            move_player_card(map, map->player_1, -1, 0);
            break;
    }
}

static void move_player_two(map_t *map, int ch)
{
    if (ch == 'z' || ch == 'Z') {
        move_player_card(map, map->player_2, 0, -1);
        return;
    }
    if (ch == 's' || ch == 'S') {
        move_player_card(map, map->player_2, 0, 1);
        return;
    }
    if (ch == 'd' || ch == 'D') {
        move_player_card(map, map->player_2, 1, 0);
        return;
    }
    if (ch == 'q' || ch == 'Q') {
        move_player_card(map, map->player_2, -1, 0);
        return;
    }
}

void manage_imputs(map_t *map, char const *filepath, int ch)
{
    if (ch == ' ') {
        load_map_in_mem(filepath, map);
        check_map(map);
    }
    move_player_one(map, ch);
    if (map->player_count == 2) {
        move_player_two(map, ch);
    }
}
