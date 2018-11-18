/*
** EPITECH PROJECT, 2018
** sign.c
** File description:
** bistromatique
*/

#include "../../include/eval_expr.h"
#include <stdlib.h>

int sign_calc(char *expr, char **av, int i, int k)
{
    int s = 0;
    int a = 0;
    int num;

    for (; expr[i] != '\0'; i++)
        if (expr[i] != av[2][3] && expr[i] != av[2][2] && a == 0)
            a = 1;
        else if (expr[i] == av[2][3] && a == 0)
            s++;
    for (int j = 0; j != i; j++)
        if (condition_base(expr[j], av))
            num++;
    if (num == 1 || (k == 0 && s % 2 == 0) || (expr[k - 1] == av[2][0] \
       && s % 2 == 0))
        return (3);
    else if (s % 2 == 0)
        return (0);
    else
        return (1);
}

char *sign(char *expr, char **av, int size)
{
    char *stock = malloc(sizeof(char) * size);
    int k = 0;

    for (int i = 0, a = 0; expr[i] != '\0'; i++) {
        if (expr[i] != av[2][3] && expr[i] != av[2][2]) {
            stock[k++] = expr[i];
            a = 0;
        } else if ((expr[i] == av[2][3] || expr[i] == av[2][2]) && a == 0)
            a = 1;
        if (a == 1 && sign_calc(expr, av, i, k) == 0) {
            stock[k++] = av[2][2];
            a = 2;
        } else if (a == 1 && sign_calc(expr, av, i, k) == 1) {
            stock[k++] = av[2][3];
            a = 2;
        } else if (a == 1 && sign_calc(expr, av, i, k) == 3)
            a = 2;
    }
    stock[k] = '\0';
    return (stock);
}