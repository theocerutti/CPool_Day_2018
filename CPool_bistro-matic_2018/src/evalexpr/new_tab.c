/*
** EPITECH PROJECT, 2018
** new_tab.c
** File description:
** bistromatique
*/

#include <stdlib.h>
#include "../../include/eval_expr.h"
#include "../../include/my.h"

int len_tab(char **number)
{
    int i = 0;

    for (i = 0; number[i] != NULL; i++);
    return (i);
}

char **modify(char *result, int i, char **number)
{
    char **p = number;

    number[i - 1] = result;
    for (; number[i] != NULL; i++) {
        if (number[i + 2] != NULL)
            number[i] = p[i + 2];
    }
    number[i - 2] = NULL;
    return (number);
}

char **negative_modify(char *result, int i, char **number)
{
    char **p = number;

    number[i - 1] = result;
    for (; number[i] != NULL; i++) {
        if (number[i + 1] != NULL)
            number[i] = p[i + 1];
    }
    number[i - 1] = NULL;
    return (number);
}

char **negative_parenthesis(char **number, int start_p, char **av)
{
    int len;
    int k = 1;
    int i = 0;

    for (len = 0; number[1][len] != '\0'; len++);
    number[0] = malloc(sizeof(*number) * (len + 1));
    number[0][0] = av[2][3];
    for (i = 0; number[1][i] != '\0'; i++) {
        number[0][k] = number[1][i];
        k++;
    }
    for (i = start_p; number[i] != NULL; i++) {
        if (number[i + 1] != NULL)
            number[i] = number[i + 1];
    }
    number[i - 1] = NULL;
    return (number);
}

char **del_parenthesis(char **number, int start_p, int end_p, char **av)
{
    int i;

    for (i = start_p; number[i] != NULL; i++) {
        if (number[i + 1] != NULL)
            number[i] = number[i + 1];
    }
    for (i = end_p - 1; number[i + 1] != NULL; i++) {
        if (number[i + 1] != NULL)
        number[i] = number[i + 1];
    }
    number[i - 1] = NULL;
    if (condition_operator(number[0][0], av) && number[0][1] == '\0' \
       && number[0][0] != av[2][0]) {
        if (condition_base(number[start_p][0], av) && start_p != 0 && \
           number[start_p - 1][0] == av[2][3]) {
            number = negative_parenthesis(number, start_p, av);
        }
    }
    return (number);
}
