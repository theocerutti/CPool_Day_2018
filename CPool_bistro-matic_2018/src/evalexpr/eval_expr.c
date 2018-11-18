/*
** EPITECH PROJECT, 2018
** eval_expr.c
** File description:
** bistromatique task 02
*/

#include "../../include/eval_expr.h"
#include <stdlib.h>

char **default_calc(int start_p, int end_p, char **number, char **av)
{
    char *result = NULL;

    for (int i = start_p; i != end_p + 1; i++) {
        if (i != 0 && condition_base(number[i][0], av) && \
           (condition_base(number[i - 1][0], av) || \
           number[i - 1][0] == av[2][3])) {
            result = coperator(number[i], number[i - 1], '+', av);
            return ((negative_modify(result, i, number)));
        }
    }
    return (number);
}

char **basic_operator(int start_p, int end_p, char **number, char **av)
{
    char *result = NULL;

    for (int i = start_p; i != end_p + 1; i++) {
        if (number[i][0] == av[2][2]) {
            result = coperator(number[i - 1], number[i + 1], '+', av);
            return ((modify(result, i, number)));
        }
        if (number[i][0] == av[2][3] && i != 0 && number[i][1] == '\0' && \
           number[i - 1][0] != av[2][0]) {
            result = coperator(number[i - 1], number[i + 1], '-', av);
            return ((modify(result, i, number)));
        }
        if (number[i][0] == av[2][3] && i != 0 && \
           number[i - 1][0] != av[2][0]) {
            result = coperator(number[i - 1], number[i], '+', av);
            return ((negative_modify(result, i, number)));
        }
    }
    return (default_calc(start_p, end_p, number, av));
}

char **multiply(int start_p, int end_p, char **number, char **av)
{
    char *result = NULL;

    for (int i = start_p; i != end_p; i++) {
        if (number[i][0] == av[2][4]) {
            result = coperator(number[i - 1], number[i + 1], '*', av);
            return ((modify(result, i, number)));
        }
        if (number[i][0] == av[2][5]) {
            divided_by_zero(number[i + 1], av);
            result = coperator(number[i - 1], number[i + 1], '/', av);
            return ((modify(result, i, number)));
        }
        if (number[i][0] == av[2][6]) {
            divided_by_zero(number[i + 1], av);
            result = coperator(number[i - 1], number[i + 1], '%', av);
            return ((modify(result, i, number)));
        }
    }
    return (basic_operator(start_p, end_p, number, av));
}

char **parenthesis(char **number, char **av, int len)
{
    int start_p = -1;
    int end_p = -1;
    int a = 0;

    for (int i = 0; i != len; i++) {
        if (number[i][0] == av[2][0]) {
            start_p = i;
            a = 1;
        } else if (number[i][0] == av[2][1] && a == 1) {
            end_p = i;
            a = 2;
        }
    }
    if (start_p != -1 && end_p != -1) {
        if (end_p - start_p == 2)
            return (del_parenthesis(number, start_p, end_p, av));
        else
            return (multiply(start_p + 1, end_p + 1, number, av));
    } else
        return (multiply(0, len - 1, number, av));
}

char *evalexpr(char **av, char *expr_old, int size)
{
    char *expr = sign(expr_old, av, size);
    int len = counter(av, expr);
    char **number = NULL;

    operator_base(av);
    char_error(expr, av);
    number = tab_maker(av, number, expr);
    void_parenthesis(number, av);
    len = len_tab(number);
    for (; len != 1 && number[1][0] != '\0'; len = len_tab(number))
        number = parenthesis(number, av, len);
    return (number[0]);
}
