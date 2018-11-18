/*
** EPITECH PROJECT, 2018
** my_strappend
** File description:
** my_strappend
*/

#include <stdlib.h>

char *my_strappend(char *src, char ch)
{
    int len = 0;
    char *new_src;

    for (len = 0; src[len] != '\0'; len++);
    new_src = malloc((3 + len) * sizeof(char));
    if (new_src == NULL)
        exit(84);
    for (len = 0; src[len] != '\0'; len++)
        new_src[len] = src[len];
    new_src[len] = ch;
    new_src[len + 1] = '\0';
    return (new_src);
}
