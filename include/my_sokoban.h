/*
** EPITECH PROJECT, 2023
** my_popup.h
** File description:
** main header file for the my_sokoban.h
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <time.h>

typedef struct player_s {
    int x;
    int y;
    char skin;
} player_t;

typedef struct map_s {
    char **map;
    int x;
    int y;
    int player_count;
    int box_count;
    int location_count;
    player_t *player_1;
    player_t *player_2;
} map_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nbr);
int my_strlen(char const *str);
int mini_printf(char const *format, ...);
int my_strcmp(char const *s1, char const *s2);

int my_open(char const *filepath, int *fd);
int my_read(int fd, char *buff, int nb_bytes);
int my_close(int fd);
int load_map(char const *filepath, map_t *map);
int get_size_of_map(char const *filepath, map_t *map);
int load_map_in_mem(char const *filepath, map_t *map);
int check_map(map_t *map);
void print_map(map_t *map);
void manage_imputs(map_t *map, char const *filepath, int ch);
int is_loose(map_t *map);
int is_won(map_t *map);
int move_player_card(map_t *map, player_t *p, int m_x, int m_y);
int won(void);
int loose(void);
int game_over(int is_won, map_t *map);
void free_map(map_t *map);
#endif /* !MY_SOKOBAN_H_ */
