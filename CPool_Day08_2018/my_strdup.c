/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** Day08 -- task01
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len_src = 0;
    int i = 0;
    char *dest = NULL;

    for (len_src = 0; src[len_src] != '\0'; len_src++);
    dest = malloc(len_src);
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i + 1] = '\0';
    return (dest);
}
