/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** display a number
** Return the number of figures printed
*/

#include "../include/my_sokoban.h"

static int my_put_nbr_rec(int nbr, int characters)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
        characters += 1;
    }
    if (nbr == 0 && characters == 0) {
        my_putchar('0');
        characters += 1;
    }
    if (nbr > 0) {
        characters += 1;
        my_put_nbr_rec(nbr / 10, characters);
        my_putchar((nbr % 10) + '0');
    }
    return characters;
}

int my_put_nbr(int nbr)
{
    int char_count = 0;

    return (my_put_nbr_rec(nbr, char_count));
}
