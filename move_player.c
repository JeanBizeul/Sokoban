/*
** EPITECH PROJECT, 2023
** move_player.c
** File description:
** functions used to move the player around the map,
** resets the map if SPECEBAR pressed
*/

#include "include/my_sokoban.h"

static int move_box(map_t *map, player_t *p, int m_y, int m_x)
{
    char next_c;

    if (p->x + m_x < 0 || p->x + m_x > map->x
        || p->y + m_y < 0 || p->y + m_y >= map->y)
        return 0;
    next_c = map->map[p->y + m_y][p->x + m_x];
    if (next_c == ' ') {
        map->map[p->y + m_y][p->x + m_x] = 'X';
        return 1;
        p->x += m_x / 2;
        p->y += m_y / 2;
    }
    if (next_c == 'O') {
        map->map[p->y + m_y][p->x + m_x] = 'x';
        return 1;
        p->x += m_x / 2;
        p->y += m_y / 2;
    } else {
        return 0;
    }
}

static void change_player_pos_uppercase_p(player_t *p, map_t *map,
    int m_y, int m_x)
{
    char next_obj = map->map[p->y + m_y][p->x + m_x];

    map->map[p->y][p->x] = ' ';
    if (next_obj == 'x' || next_obj == 'O') {
        map->map[p->y + m_y][p->x + m_x] = 'p';
        p->skin = 'p';
    } else {
        map->map[p->y + m_y][p->x + m_x] = 'P';
        p->skin = 'P';
    }
}

static void change_player_pos_lowercase_p(player_t *p, map_t *map,
    int m_y, int m_x)
{
    char next_obj = map->map[p->y + m_y][p->x + m_x];

    map->map[p->y][p->x] = 'O';
        if (next_obj == 'x' || next_obj == 'O') {
            map->map[p->y + m_y][p->x + m_x] = 'p';
            p->skin = 'p';
        } else {
            map->map[p->y + m_y][p->x + m_x] = 'P';
            p->skin = 'P';
        }
}

static void change_player_pos(player_t *p, map_t *map, int m_y, int m_x)
{
    if (p->skin == 'P') {
        change_player_pos_uppercase_p(p, map, m_y, m_x);
    } else {
        change_player_pos_lowercase_p(p, map, m_y, m_x);
    }
    p->x += m_x;
    p->y += m_y;
}

int move_player_card(map_t *map, player_t *p, int m_x, int m_y)
{
    char next_obj;

    if (p->x + m_x < 0 || p->x + m_x > map->x
        || p->y + m_y < 0 || p->y + m_y >= map->y)
        return 0;
    next_obj = map->map[p->y + m_y][p->x + m_x];
    if (next_obj == '\n' || next_obj == '\0' || next_obj == '#')
        return 0;
    if (next_obj == ' ')
        change_player_pos(p, map, m_y, m_x);
    if (next_obj == 'O')
        change_player_pos(p, map, m_y, m_x);
    if (next_obj == 'X') {
        if (move_box(map, p, m_y * 2, m_x * 2))
            change_player_pos(p, map, m_y, m_x);
    }
    if (next_obj == 'x') {
        if (move_box(map, p, m_y * 2, m_x * 2))
            change_player_pos(p, map, m_y, m_x);
    }
    return 0;
}