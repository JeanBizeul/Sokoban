/*
** EPITECH PROJECT, 2023
** print_map.c
** File description:
** prints the map given as a 2D array
*/

#include "include/my_sokoban.h"

static void print_char(map_t *map, int y, int x)
{
    if (map->map[y][x] == 'x') {
        attron(COLOR_PAIR(5));
        mvprintw((LINES / 2) - (map->y / 2) + y,
            (COLS / 2) - (map->x / 2) + x, "X");
        attroff(COLOR_PAIR(5));
        return;
    }
    if (map->map[y][x] == 'X') {
        attron(COLOR_PAIR(4));
        mvprintw((LINES / 2) - (map->y / 2) + y,
            (COLS / 2) - (map->x / 2) + x, "X");
        attroff(COLOR_PAIR(4));
        return;
    }
    if (map->map[y][x] == 'p' || map->map[y][x] == 'P') {
        attron(COLOR_PAIR(1));
        mvprintw((LINES / 2) - (map->y / 2) + y,
            (COLS / 2) - (map->x / 2) + x, "P");
        attroff(COLOR_PAIR(1));
        return;
    }
    if (map->map[y][x] == 'O') {
        attron(COLOR_PAIR(3));
        mvprintw((LINES / 2) - (map->y / 2) + y,
            (COLS / 2) - (map->x / 2) + x, "O");
        attroff(COLOR_PAIR(3));
        return;
    }
    if (map->map[y][x] == '#') {
        attron(COLOR_PAIR(6));
        mvprintw((LINES / 2) - (map->y / 2) + y,
            (COLS / 2) - (map->x / 2) + x, "#");
        attroff(COLOR_PAIR(6));
        return;
    }
    mvprintw((LINES / 2) - (map->y / 2) + y,
        (COLS / 2) - (map->x / 2) + x, "%c", map->map[y][x]);
}

void print_map(map_t *map)
{
    if (LINES < map->y + 2 || COLS < map->x) {
        mvprintw(LINES / 2, COLS / 2 - 10, "Terminal too small.");
        mvprintw(LINES / 2 + 1, COLS / 2 - 10, "Please enlarge it.");
        return;
    }
    attron(COLOR_PAIR(4));
    mvprintw((LINES / 2) - (map->y / 2) - 1, COLS / 2 - 10, "Press A to quit map");
    attroff(COLOR_PAIR(4));
    for (int y = 0; map->map[y] != NULL; y ++) {
        for (int x = 0; map->map[y][x] != '\0'; x ++) {
            print_char(map, y, x);
        }
    }
}
