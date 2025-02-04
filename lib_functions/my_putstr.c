/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** displays the caracters of a string
*/

#include "../include/my_sokoban.h"

int my_putstr(char const *str)
{
    int i = 0;
    char characters = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        characters += 1;
        i += 1;
    }
    return characters;
}
