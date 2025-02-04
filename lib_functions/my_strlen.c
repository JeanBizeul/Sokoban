/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** return the number of caracter of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}
