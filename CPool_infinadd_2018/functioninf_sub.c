/*
** EPITECH PROJECT, 2018
** function.c
** File description:
** function of infin_add.c
*/

#include <stdlib.h>
#include "include/my_macro_abs.h"
#include "include/my.h"
#include "include/function.h"

char *malloc_result_neg(char *av[], int *p_len_big, char *str_nb1, char *str_nb2)
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

char *calculate_neg(char *str_nb1, char *str_nb2, char *result, int len_biggest)
{
    int num = 0;
    char rest = '0';
    int minus = 0;
    int minus_1 = 0;
    int minus_2 = 0;

    for (int i = 0; str_nb1[i] != '\0' || str_nb2[i] != '\0'; i++) {
        if (str_nb1[i] == '-') {
            minus_1 = 1;
            str_nb1[i] = '0';
        } else if (str_nb2[i] == '-') {
            minus_2 = 1;
            str_nb2[i] = '0';
        }
    }
    for (int i = 0; i != len_biggest; i++)
        result[i] = '0';
    for (int i = len_biggest - 1; i >= 0; i--) {
        num = str_nb1[i] - str_nb2[i] + rest;
        if (num < '0' && i != 0) {
            result[i] = '9';
            rest -= 1;
        } else {
            rest = '0';
            result[i] = num;
        }
    }
    return (result);
}

int look_nb_biggest(char *str_nb1, char *str_nb2)
{
    int i = 0;

    if (str_nb1[0] == '-')
        return (0);
    else
        return (1);
    for (i = 0; str_nb1[i] != '\0'; i++) {
        if (str_nb1[i] > str_nb2[i])
            return (1);
    }
    return (0);
}