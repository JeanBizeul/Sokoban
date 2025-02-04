/*
** EPITECH PROJECT, 2023
** my_sokoban.c
** File description:
** main function of the sokoban project
*/

#include "./include/my_sokoban.h"

static void format_checks(int argc)
{
    if (argc == 1) {
        write(2, "file(s) or '-h' expected as the programm's argument\n", 49);
        exit(84);
    }
}

static int print_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map(file(s))\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing a wharehouse map :\n");
    my_putstr("           |-> '#' are walls\n");
    my_putstr("           |-> 'P' is the player\n");
    my_putstr("           |-> 'X' are boxes\n");
    my_putstr("           '-> 'O' are storage locations\n");
    return 0;
}

static void print_continue_screen(map_t *map, int map_count, int argc)
{
    clear();
    if (is_won(map)) {
        attron(COLOR_PAIR(5));
        mvprintw(LINES / 2 - 3, COLS / 2 - 7, "MAP COMPLETED");
        attroff(COLOR_PAIR(5));
    } else {
        attron(COLOR_PAIR(4));
        mvprintw(LINES / 2 - 3, COLS / 2 - 4.5, "MAP LOST");
        attroff(COLOR_PAIR(4));
    }
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 - 1, COLS / 2 - 10, "Spacebar : retry map");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2, COLS / 2 - 10, "A : exit game");
    attroff(COLOR_PAIR(4));
    if (map_count + 1 < argc) {
        attron(COLOR_PAIR(5));
        mvprintw(LINES / 2 + 1, COLS / 2 - 10, "N : next map (%i/%i)", map_count + 1, argc - 1);
        attroff(COLOR_PAIR(5));
        attron(COLOR_PAIR(1));
        if (map_count > 1) {
            mvprintw(LINES / 2 + 2, COLS / 2 - 10, "B : previous map (%i/%i)", map_count - 1, argc - 1);
            attroff(COLOR_PAIR(5));
        }
    } else {
        if (map_count > 1) {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + 1, COLS / 2 - 10, "B : previous map (%i/%i)", map_count - 1, argc - 1);
            attroff(COLOR_PAIR(5));
        }
    refresh();
    }
}

static int continue_playing(map_t *map, int *map_count, int argc)
{
    int ch = 0;

    while (1 + 90 * 74 - 24 > 0) {
        clear();
        if (LINES < 7 || COLS < 20) {
            mvprintw(LINES / 2, COLS / 2 - 10, "Terminal too small.");
            mvprintw(LINES / 2 + 1, COLS / 2 - 10, "Please enlarge it.");
        } else {
            print_continue_screen(map, *map_count, argc);
        }
        ch = getch();
        if (ch == 'a' || ch == 'A') {
            return 0;
        }
        if (ch == ' ') {
            return 1;
        }
        if ((ch == 'n' || ch == 'N') && *map_count + 1 < argc) {
            *map_count += 1;
            return 1;
        }
        if ((ch == 'b' || ch == 'B') && *map_count > 1) {
            *map_count -= 1;
            return 1;
        }
    }
    return 0;
}

static void game_loop(map_t *map, char const **argv, int map_count)
{
    int ch = 0;
    while (!is_loose(map) && !is_won(map) && ch != 'a' && ch != 'A') {
        clear();
        print_map(map);
        ch = getch();
        manage_imputs(map, argv[map_count], ch);
        refresh();
    }
}

static void init_colors(void)
{
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

int main(int argc, char const **argv)
{
    map_t map;
    player_t *player_1 = malloc(sizeof(player_t));
    player_t *player_2 = malloc(sizeof(player_t));
    int map_count = 1;

    format_checks(argc);
    if (!my_strcmp(argv[1], "-h"))
        return (print_h());
    map.player_1 = player_1;
    map.player_2 = player_2;
    do {
        load_map(argv[map_count], &map);
        initscr();
        init_colors();
        keypad(stdscr, 1);
        game_loop(&map, argv, map_count);
        if (!continue_playing(&map, &map_count, argc)) {
            break;
            free_map(&map);
        }
    } while (map_count < argc);
    return game_over(is_won(&map), &map);
}
