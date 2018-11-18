/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** bistromatique
*/

#include "../../include/eval_expr.h"
#include "../../include/my.h"
#include "../../include/bistromatic.h"
#include <stdlib.h>

void error_display(char *str)
{
    my_putstr(str);
    exit(84);
}

void divided_by_zero(char *str2, char **av)
{
    int counter = 0;

    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] != av[1][0] && str2[i] != av[2][3])
            counter++;
    }
    if (counter == 0)
        error_display(ERROR_MSG);
}

void void_parenthesis(char **number, char **av)
{
    int open_par = 0;
    int close_par = 0;
    int error = 0;

    for (int i = 0; number[i] != NULL; i++) {
        if (number[i][0] == av[2][0] && number[i + 1][0] == av[2][1])
            error = 1;
        else if (number[i][0] == av[2][0] && i != 0 && \
                 condition_base(number[i - 1][0], av))
            error = 1;
    }
    for (int i = 0; number[i] != NULL; i++) {
        if (number[i][0] == av[2][0])
            open_par++;
        else if (number[i][0] == av[2][1])
            close_par++;
    }
    if (close_par != open_par || error == 1)
        error_display(SYNTAX_ERROR_MSG);
}

void operator_error(char **number, char **av)
{
    int nb1;
    int nb2;

    for (int i = 0; number[i] != NULL; i++, nb1 = 0, nb2 = 0) {
        if (condition_operator(number[i][0], av) && number[i][0] != av[2][0] \
            && number[i][0] != av[2][1])
            nb1 = 1;
        if (number[i + 1] != NULL && condition_operator(number[i + 1][0], av) \
            && number[i + 1][0] != av[2][0] && number[i + 1][0] != av[2][1])
            nb2 = 1;
        if ((nb1 == 1 && nb2 == 1 && number[i][1] == '\0' && \
             number[i + 1][1] == '\0') || (i == 0 && \
             condition_operator(number[i][0], av) && number[i][0] != av[2][3] && \
             number[i][0] != av[2][0]))
            error_display(SYNTAX_ERROR_MSG);
        if (number[i + 1] != NULL && number[i + 1][0] == av[2][1] && \
            condition_operator(number[i][0], av) && number[i][1] == '\0' \
            && number[i][0] != av[2][1])
            error_display(SYNTAX_ERROR_MSG);
    }
}

void char_error(char *expr, char **av)
{
    int i = 0;

    for (i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < 48 || av[1][i] > 57)
            error_display(SYNTAX_ERROR_MSG);
    }
    if (i != 10)
        error_display(SYNTAX_ERROR_MSG);
    for (i = 0; expr[i] != '\0'; i++) {
        if (condition_operator(expr[i], av) == 0 && \
           condition_base(expr[i], av) == 0)
            error_display(SYNTAX_ERROR_MSG);
        if (expr[i] == av[2][0] && condition_base(expr[i - 1], av))
            error_display(SYNTAX_ERROR_MSG);
        if (expr[i] == av[2][1] && condition_base(expr[i + 1], av))
            error_display(SYNTAX_ERROR_MSG);
    }
}
