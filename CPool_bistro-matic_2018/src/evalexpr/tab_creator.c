/*
** EPITECH PROJECT, 2018
** tab_creator.c
** File description:
** bistromatique
*/

#include "../../include/eval_expr.h"
#include <stdlib.h>

int condition_operator(char c, char **av)
{
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (c == av[2][i])
            return (1);
    }
    return (0);
}

int condition_base(char c, char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (c == av[1][i])
            return (1);
    }
    return (0);
}

char *tab_fill(char **av, char *number, char **p)
{
    int start = -1;
    int end = -1;
    int j;

    for (j = 0; p[0][j] != '\0'; j++) {
        if ((condition_base(p[0][j], av) || p[0][j] == av[2][3]) && start == -1)
            start = 0;
        else if (condition_base(p[0][j], av) == 0 && start != -1 && end == -1)
            end = j;
    }
    if (end == -1)
        end = j;
    number = malloc(sizeof(char) * (end - start + 2));
    for (; start != end; start++)
        number[start] = p[0][start];
    p[0] += start;
    number[start + 1] = '\0';
    return (number);
}

int counter(char **av, char *expr)
{
    int counter = 0;
    int a = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if ((condition_base(expr[i], av) || expr[i] == av[2][3]) && a == 0) {
            counter++;
            a = 1;
        } else if (condition_base(expr[i], av) == 0 && a == 1)
            a = 0;
        if (condition_operator(expr[i], av) && expr[i] != av[2][3])
            counter++;
        if (expr[i] == av[2][0] && expr[i - 1] == av[2][3])
            counter++;
    }
    return (counter);
}

char **tab_maker(char **av, char **number, char *expr)
{
    int count = counter(av, expr);
    int i;
    char **p;

    p = malloc(sizeof(*p) * 1);
    p[0] = expr;
    number = malloc(sizeof(*number) * (count + 1));
    for (i = 0; i != count; i++) {
        if (condition_operator(p[0][0], av) && p[0][0] != av[2][3]) {
            number[i] = malloc(sizeof(char) * 1);
            number[i][0] = p[0][0];
            p[0]++;
        } else
            number[i] = tab_fill(av, number[i], p);
    }
    number[i] = NULL;
    void_parenthesis(number, av);
    operator_error(number, av);
    return (number);
}
