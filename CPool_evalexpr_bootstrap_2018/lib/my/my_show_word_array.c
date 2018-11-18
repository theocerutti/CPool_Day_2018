/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** Day08 -- task03
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    for (i = 0; tab[i] != 0; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            my_putchar(tab[i][j]);
        my_putchar('\n');
    }
    return (0);
}
