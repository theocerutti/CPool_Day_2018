/*
** EPITECH PROJECT, 2018
** concat_params
** File description:
** Day08 -- task02
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    char *str;
    int i = 1;
    int e = 0;

    while (argv[e] != '\0') {
        my_putstr(argv[e]);
        if (argv[e + 1] != '\0')
            my_putchar('\n');
        e += 1;
        i += 1;
    }
    str = malloc(i + argc);
    return (str);
}
