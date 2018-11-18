/*
** EPITECH PROJECT, 2018
** EvalEXPR
** File description:
** evalEXPR
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/function.h"

char *malloc_without_space(char const *expr)
{
    char *result;
    int len_expr_without_space = my_strlen(expr);

    for (int index = 0; expr[index] != '\0'; index++) {
        if (expr[index] == '(' || expr[index] == ')')
            len_expr_without_space -= 1;
    }
    result = malloc(sizeof(char) * len_expr_without_space);
    for (int i = 0; i != len_expr_without_space; i++)
        result[i] = '0';
    return (result);
}

int take_priority(char op)
{
    int mult_div_modul = 2;
    int plus_sub = 1;
    int priority = 0;

    if (op == '%' || op == '*' || op == '/')
        priority = mult_div_modul;
    else if (op == '+' || op == '-')
        priority = plus_sub;
    else
        priority = 0;
    return (priority);
}

int is_less_priority(char operator, char operator_stack)
{
    int priority_op = take_priority(operator);
    int priority_op_stack = take_priority(operator_stack);

    if (priority_op <= priority_op_stack)
        return (1);
    else
        return (0);
}

int operation(int nb1, int nb2, char op)
{
    if (op == '+')
        return (nb2 + nb1);
    else if (op == '-')
        return (nb2 - nb1);
    else if (op == '*')
        return (nb2 * nb1);
    else if (op == '/')
        return (nb2 / nb1);
    else if (op == '%')
        return (nb2 % nb1);
    return (0);
}

char *supp_zero(char *str)
{
    for (int i = 0; str[i] == '0'; i++)
        str = my_strdelete(str, 1);
    str = my_strdelete(str, 1);
    str[my_strlen(str)] = '\0';
    return (str);
}