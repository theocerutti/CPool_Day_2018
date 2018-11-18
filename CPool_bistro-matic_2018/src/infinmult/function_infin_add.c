/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** infin_add calc
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/func_infin_mult.h"

char *malloc_result(int *p_len_big, char *str_nb1, char *str_nb2)
{
    int len_1 = my_strlen(str_nb1);
    int len_2 = my_strlen(str_nb2);
    char *result;

    if (len_1 > len_2) {
        result = malloc(sizeof(char) * (len_1 + 2));
        *p_len_big = len_1;
    } else {
        result = malloc(sizeof(char) * (len_2 + 2));
        *p_len_big = len_2;
    }
    if (result == NULL)
        exit(84);
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
        } else
            rest = '0';
        result[i + 1] = num;
    }
    return (result);
}

char *transform_str_zero_add(char *str_nb, int len_1, int len_2)
{
    int diff = len_1 - len_2;

    diff = ABS(diff);
    for (int i = 0; i != diff; i++)
        str_nb = my_strappend_first(str_nb, '0');
    return (str_nb);
}
