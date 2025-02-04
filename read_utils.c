/*
** EPITECH PROJECT, 2023
** read_utils.c
** File description:
** open, read and close functions with personnal errors messages included
*/

#include "./include/my_sokoban.h"

int my_open(char const *filepath, int *fd)
{
    *fd = open(filepath, O_RDONLY);
    if (*fd == -1) {
        write(2, "can't open file", 16);
        return -1;
    } else {
        return 1;
    }
}

int my_read(int fd, char *buff, int nb_bytes)
{
    int read_ret = read(fd, buff, nb_bytes);

    if (read_ret == -1) {
        write(2, "read failed", 12);
        return -1;
    }
    return read_ret;
}

int my_close(int fd)
{
    if (close(fd) == -1) {
        write(2, "error while closing a file", 27);
        return -1;
    } else {
        return 1;
    }
}
