/*
** EPITECH PROJECT, 2018
** EvalEXPR
** File description:
** evalEXPR
*/

#include <stdlib.h>
#include "include/function.h"
#include "include/stack.h"
#include "include/my.h"

char *infix_to_postfix(char const *expr)
{
    int index = 0;
    int index_postfix = 0;
    char operator;
    char *result = malloc_without_space(expr);
    struct stack_struct* stack = create_stack(my_strlen(expr));

    for (index = 0; expr[index] != '\0'; index++) {
        if (expr[index] >= '0' && expr[index] <= '9') {
            result[index_postfix] = expr[index];
            index_postfix += 1;
        } else {
            if (expr[index] == '(')
                push(stack, expr[index]);
            else if (expr[index] == ')') {
                operator = pop(stack);
                while (operator != '(') {
                    result[index_postfix] = operator;
                    index_postfix += 1;
                    operator = pop(stack);
                }
            } else {
                while (is_empty(stack) != 1 && \
                is_less_priority(expr[index], peek(stack)) == 1) {
                    result[index_postfix] = pop(stack);
                    index_postfix += 1;
                }
                push(stack, expr[index]);
            }
        }
    }
    for (; is_empty(stack) != 1; index_postfix++)
        result[index_postfix] = pop(stack);
    return (result);
}

int postfix_to_result(char const *expr)
{
    struct stack_struct* stack = create_stack(10);
    int index = 0;
    int nb1 = 0;
    int nb2 = 0;
    int nb_result = 0;

    for (index = 0; expr[index] != '\0'; index++) {
        if (expr[index] >= '0' && expr[index <= '9'])
            push(stack, expr[index]);
        else {
            nb1 = pop(stack) - '0';
            nb2 = pop(stack) - '0';
            push(stack, operation(nb1, nb2, expr[index]) + 48);
        }
    }
    nb_result = pop(stack);
    if (nb_result > 9)
        nb_result -= 48;
    return (nb_result);
}

int eval_expr(char const *str)
{
    char *result_postfix;
    int final_result = 0;

    if (str[1] == '\0' && str[0] >= '0' && str[0] <= '9')
        return (str[0] - 48);
    else if (str[0] == '\0')
        return (0);
    else if (my_str_isnum(str))
        return (my_getnbr(str));
    result_postfix = infix_to_postfix(str);
    final_result = postfix_to_result(result_postfix);
    return (final_result);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}