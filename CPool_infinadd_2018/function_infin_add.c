/*
** EPITECH PROJECT, 2018
** function.c
** File description:
** function of infin_add.c
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/my_macro_abs.h"
#include "include/function.h"

void print_result(char *r, char *s1, char *s2)
{
    int i = 0;

    for (i = 0; r[i] < '1'; i++);
    for (int j = i; r[j] != '\0'; j++)
        my_putchar(r[j]);
}

char *malloc_result(char *av[], int *p_len_big, char *str_nb1, char *str_nb2)
{
    int len_1 = my_strlen(av[1]);
    int len_2 = my_strlen(av[2]);
    char *result;

    if (len_1 > len_2) {
        result = malloc(sizeof(char) * (len_1 + 2));
        *p_len_big = len_1;
    } else {
        result = malloc(sizeof(char) * (len_2 + 2));
        *p_len_big = len_2;
    }
    return (result);
}

char *calculate(char *str_nb1, char *str_nb2, char *result, int len_biggest)
{
    int num = 0;
    char rest = '0';
    int i = 0;

    for (i = 0; i != len_biggest + 1; i++)
        result[i] = '0';
    for (i = len_biggest - 1; i >= 0; i--) {
        num = str_nb1[i] + str_nb2[i] - '0' + rest - '0';
        if (num >= 58) {
            rest = '1';
            num -= 10;
            result[i] = rest;
        }
        else
            rest = '0';
        result[i + 1] = num;
    }
    return (result);
}

char *transform_str_zero(char *str_nb, int len_biggest, int len_1, int len_2)
{
    int diff = len_1 - len_2;

    diff = ABS(diff);
    for (int i = 0; i != diff; i++)
        str_nb = my_strappend_first(str_nb, '0');
    return (str_nb);
}

int look_for_minus(char *str_nb1, char *str_nb2)
{
    if (str_nb1[0] == '-' && str_nb2[0] == '-') {
        my_putchar('-');
        return (1);
    }
    return (0);
}