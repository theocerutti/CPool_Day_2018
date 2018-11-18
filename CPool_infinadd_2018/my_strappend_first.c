/*
** EPITECH PROJECT, 2018
** my_strappend.c
** File description:
** Function permits to add an element to the end of arrays
*/

#include <stdlib.h>

char *my_strappend_first(char *src, char ch)
{
    int len = 0;
    char *new_src;

    for (len = 0; src[len] != '\0'; len++);
    new_src = malloc(sizeof(char) + len * sizeof(char));
    new_src[0] = ch;
    for (len = 0; src[len] != '\0'; len++)
        new_src[len + 1] = src[len];
    new_src[len + 1] = '\0';
    return (new_src);
}
