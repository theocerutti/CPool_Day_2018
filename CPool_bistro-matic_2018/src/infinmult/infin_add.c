/*
** EPITECH PROJECT, 2018
** infin_add.c
** File description:
** Add 2 number, handle infinite numbers
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/func_infin_mult.h"

int look_if_same(char *str_nb1, char *str_nb2)
{
    str_nb1++;
    str_nb2++;
    return (my_strcmp(str_nb1, str_nb2));
}

char *infin_add(char *str_nb1, char *str_nb2)
{
    int len_biggest = 0;
    int *p_len_big = &len_biggest;
    int len_1 = my_strlen(str_nb1);
    int len_2 = my_strlen(str_nb2);
    char *result;

    result = malloc_result(p_len_big, str_nb1, str_nb2);
    if (result == NULL)
        exit(84);
    if (len_1 > len_2)
        str_nb2 = transform_str_zero_add(str_nb2, len_1, len_2);
    else if (len_1 < len_2)
        str_nb1 = transform_str_zero_add(str_nb1, len_1, len_2);
    result = calculate(str_nb1, str_nb2, result, len_biggest);
    return (result);
}
