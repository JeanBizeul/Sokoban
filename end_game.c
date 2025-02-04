/*
** EPITECH PROJECT, 2023
** end_game.c
** File description:
** functions managing the end of the game
*/

#include "include/my_sokoban.h"

void free_map(map_t *map)
{
    free(map->player_1);
    if (map->player_count == 2)
        free(map->player_2);
    for (int y = 0; y <= map->y; y ++) {
        free(map->map[y]);
    }
    free(map->map);
}

int game_over(int is_won, map_t *map)
{
    clear();
    print_map(map);
    refresh();
    free_map(map);
    endwin();
    if (is_won) {
        return 0;
    } else {
        return 1;
    }
}
