/*
** EPITECH PROJECT, 2018
** error2.c
** File description:
** bistromatique
*/

#include "../../include/eval_expr.h"
#include "../../include/bistromatic.h"
#include <stdlib.h>

int count_operator(char c, char **av)
{
    int j = 0;

    for (int i = 0; av[2][i] != '\0'; i++) {
        if (c == av[2][i])
            j++;
    }
    return (j);
}

int count_base(char c, char **av)
{
    int j = 0;

    for (int i = 0; av[1][i] != '\0'; i++) {
        if (c == av[1][i])
            j++;
    }
    return (j);
}

void operator_base(char **av)
{
    int count = 0;

    for (int i = 0; av[1][i] != '\0'; i++) {
        if (condition_operator(av[1][i], av))
            error_display(SYNTAX_ERROR_MSG);
    }
    for (int i = 0; av[2][i]; i++) {
        count = count_operator(av[2][i], av);
        if (count > 1)
            error_display(SYNTAX_ERROR_MSG);
    }
    for (int i = 0; av[1][i]; i++) {
        count = count_base(av[1][i], av);
        if (count > 1)
            error_display(SYNTAX_ERROR_MSG);
    }
}
