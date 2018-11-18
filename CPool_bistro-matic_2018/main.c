/*
** EPITECH PROJECT, 2018
** bistromatique.c
** File description:
** project CPool_2018
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "include/eval_expr.h"
#include "include/my.h"
#include "include/bistromatic.h"

int my_atoi(char const *str)
{
    int number = 0;
    int len;
    int j = 1;
    int a = 0;

    for (len = 0; str[len] != '\0'; len++);
    if (str[0] == '-')
        a = 1;
    for (; len != a; len--) {
        number += (str[len - 1] - 48) * j;
        j *= 10;
    }
    if (a == 1)
        number *= -1;
    return (number);
}

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4 || (av[1][0] == '-' && av[1][1] == 'h')) {
        my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n- operators:");
        my_putstr(" the symbols for the parentheses and the 5 operators\n");
        my_putstr("- size_read: number of characters to be read\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    my_putstr(evalexpr(av, expr, size));
    my_putchar('\n');
    return (EXIT_SUCCESS);
}
