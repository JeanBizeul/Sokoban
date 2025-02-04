/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** printf replica but only with %d %i %s %c
*/

#include <stdarg.h>
#include "../include/my_sokoban.h"
#include <unistd.h>

static int my_print_params(va_list args, char const *format, int i)
{
    if (format[i + 1] == '%') {
        my_putchar('%');
        return 1;
    }
    if (format[i + 1] == 's') {
        return my_putstr(va_arg(args, char *));
    }
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(args, int));
        return 1;
    }
    if ( format[i + 1] == 'd' || format[i + 1] == 'i') {
        return my_put_nbr(va_arg(args, int));
    }
    return 0;
}

int mini_printf(char const *format, ...)
{
    int characters = 0;
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i += 1) {
        if (format[i] == '%') {
            characters += my_print_params(args, format, i);
            i += 1;
        } else {
            my_putchar(format[i]);
            characters += 1;
        }
    }
    va_end(args);
    return characters;
}
