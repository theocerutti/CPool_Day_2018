/*
** EPITECH PROJECT, 2018
** operator.c
** File description:
** bistromatic
*/

#include "../../include/eval_expr.h"
#include "../../include/divide.h"
#include "../../include/modulo.h"
#include "../../include/func_infin_mult.h"
#include "../../include/add_less.h"
#include <stdlib.h>

char *negative_str(char *str2, char *str1)
{
    char *str3;
    int i;
    int k = 0;

    for (i = 0; str2[i] != '\0'; i++);
    str3 = malloc(sizeof(char) * (i + 1));
    str3[k] = '-';
    k++;
    for (i = 0; str2[i] != '\0'; i++) {
        str3[k] = str2[i];
        k++;
    }
    return (add_less(str1, str3));
}

char *calc_call(char *str1, char *str2, char op, char *str_result)
{
    switch(op) {
        case '*':
            str_result = infin_multi(str1, str2);
            break;
        case '/':
            str_result = divide(str1, str2);
            break;
        case '%':
            str_result = modulo(str1, str2);
            break;
        case '+':
            str_result = add_less(str1, str2);
            break;
        case '-':
            str_result = negative_str(str2, str1);
            break;
    }
    return (str_result);
}

char *coperator(char *str1, char *str2, char op, char **av)
{
    char *str_result = NULL;

    if (str1[0] == av[2][3])
        str1[0] = '-';
    if (str2[0] == av[2][3])
        str2[0] = '-';
    if (((op == '-' && str2[0] == '-') || (op == '+' && \
       str2[0] == '-' && str2[1] == av[1][0])) || (op == '+' && \
       str2[0] == '-' && str1[0] == '-' && str1[1] == '\0')) {
        op = '+';
        str2++;
    }
    str_result = calc_call(str1, str2, op, str_result);
    if (str_result[0] == '-')
        str_result[0] = av[2][3];
    return (str_result);
}
