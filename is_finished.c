/*
** EPITECH PROJECT, 2023
** is_finished.c
** File description:
** check if the game is finished or not
*/

#include "include/my_sokoban.h"

static int check_up(map_t *map, int x, int y)
{
    if (y > 0) {
        if (map->map[y - 1][x] == '#' || map->map[y - 1][x] == '\n'
            || map->map[y - 1][x] == '\0') {
            return 1;
        } else {
            return 0;
            }
    } else {
        return 1;
    }
}

static int check_down(map_t *map, int x, int y)
{
    if (y < map->y - 1) {
        if (map->map[y + 1][x] == '#' || map->map[y + 1][x] == '\n'
            || map->map[y + 1][x] == '\0') {
            return 1;
        } else {
            return 0;
            }
    } else {
        return 1;
    }
}

static int check_right(map_t *map, int x, int y)
{
    if (x < map->x) {
        if (map->map[y][x + 1] == '#' || map->map[y][x + 1] == '\n'
            || map->map[y][x + 1] == '\0') {
            return 1;
        } else {
            return 0;
            }
    } else {
        return 1;
    }
}

static int check_left(map_t *map, int x, int y)
{
    if (x > 0) {
        if (map->map[y][x - 1] == '#' || map->map[y][x - 1] == '\n'
            || map->map[y][x - 1] == '\0') {
            return 1;
        } else {
            return 0;
            }
    } else {
        return 1;
    }
}

static int check_around(char *around)
{
    if (around[0] && around[2]) {
        my_putchar('A');
        return 1;
    }
    if (around[2] && around[1]) {
        my_putchar('B');
        return 1;
    }
    if (around[1] && around[3]) {
        my_putchar('C');
        return 1;
    }
    if (around[3] && around[0]) {
        my_putchar('D');
        return 1;
    }
    return 0;
}

static int is_box_stuck(map_t *map, int x, int y)
{
    char around[4] = {0, 0, 0, 0};

    if (map->map[y][x] != 'X' && map->map[y][x] != 'x')
        return 0;
    around[0] = check_up(map, x, y);
    around[1] = check_down(map, x, y);
    around[2] = check_right(map, x, y);
    around[3] = check_left(map, x, y);
    return check_around(around);
}

int is_loose(map_t *map)
{
    int stucked_boxes = 0;

    for (int y = 0; map->map[y] != NULL; y ++) {
        for (int x = 0; map->map[y][x] != '\0'; x ++) {
            stucked_boxes += is_box_stuck(map, x, y);
        }
    }
    if (stucked_boxes >= map->box_count) {
        return 1;
    } else {
        return 0;
    }
}

static int is_box_placed(map_t *map, int x, int y)
{
    if (map->map[y][x] == 'x') {
        return 1;
    } else {
        return 0;
    }
}

int is_won(map_t *map)
{
    int placed_boxes = 0;

    for (int y = 0; map->map[y] != NULL; y ++) {
        for (int x = 0; map->map[y][x] != '\0'; x ++) {
            placed_boxes += is_box_placed(map, x, y);
        }
    }
    if (placed_boxes >= map->box_count) {
        return 1;
    } else {
        return 0;
    }
}
