/*
** EPITECH PROJECT, 2018
** boot_strap_EvalEXPR
** File description:
** boot_stap_evalEXPR
*/

#include "include/my.h"
#include <stdio.h>

int summands(char **str)
{
    return (0);
}

int my_strtol(char *str, char **endptr)
{
    return (0);
}

int number(char **str)
{
    int result = my_getnbr(str);
    return (result);
}

int main(int ac, int *av[])
{
    int first_number = number(av[1]);
    printf("%d\n", first_number);
    return (0);
}