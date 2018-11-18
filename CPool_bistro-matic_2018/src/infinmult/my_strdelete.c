/*
** EPITECH PROJECT, 2018
** my_strdelete
** File description:
** Functions permits to delete one character of an arrays
*/

#include <stdlib.h>

char *my_strdelete(char *src, int ch_to_delete)
{
    int len = 0;
    char *new_src;
    int jump = 0;
    int i = 0;

    for (len = 0; src[len] != '\0'; len++);
    new_src = malloc(len * sizeof(char) - sizeof(char));
    if (new_src == NULL)
        exit(84);
    if (ch_to_delete != 0)
        len -= 1;
    for (i = 0; i < len; i++) {
        if (i == ch_to_delete - 1)
            jump += 1;
        if (src[i] != '\0')
            new_src[i] = src[i + jump];
        new_src[len + 1] = '\0';
    }
    return (new_src);
}
