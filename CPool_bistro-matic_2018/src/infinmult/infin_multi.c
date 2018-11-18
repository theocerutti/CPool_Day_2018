/*
** EPITECH PROJECT, 2018
** infin_mult
** File description:
** Handle infinite numbers
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/func_infin_mult.h"

char *is_calc_neg(char *str_nb, int *p_isneg)
{
    if (str_nb[0] == '-') {
        str_nb++;
        *p_isneg += 2;
        return (str_nb);
    } else {
        *p_isneg -= 1;
        return (str_nb);
    }
    return (0);
}

int *assign_var(int len, int var)
{
    int *param;

    param = malloc(sizeof(int) * 2);
    param[0] = len;
    param[1] = var;
    return (param);
}

char *calc_result(char *nb1, char *nb2, char *result)
{
    int len_1 = my_strlen(nb1);
    int len_2 = my_strlen(nb2);
    int *param;

    if (len_1 > len_2) {
        nb2 = transform_str_zero(nb2, len_1, len_2);
        param = assign_var(len_2, 0);
        result = calc_multi(nb1, nb2, result, param);
    } else if (len_1 < len_2) {
        nb1 = transform_str_zero(nb1, len_1, len_2);
        param = assign_var(len_1, 0);
        result = calc_multi(nb2, nb1, result, param);
    } else {
        nb1 = my_strappend_first(nb1, '0');
        nb2 = my_strappend_first(nb2, '0');
        param = assign_var(len_1 + 1, 1);
        result = calc_multi(nb2, nb1, result, param);
    }
    return (result);
}

char *infin_multi(char *str_nb1, char *str_nb2)
{
    int len_1 = my_strlen(str_nb1);
    int len_2 = my_strlen(str_nb2);
    char *result;
    int is_neg = 0;

    if ((len_1 + len_2 > 8) || (len_1 > 8 || len_2 > 8) \
       || (len_1 > 8 && len_2 > 8))
        return ("0");
    result = malloc(sizeof(char) * (len_1 + len_2 + 1));
    if (result == NULL)
        exit(84);
    str_nb1 = is_calc_neg(str_nb1, &is_neg);
    str_nb2 = is_calc_neg(str_nb2, &is_neg);
    result = calc_result(str_nb1, str_nb2, result);
    for (int i = 0; result[0] == '0' && result[1] != '\0'; i++)
        result = my_strdelete(result, 1);
    if (is_neg == 1 && ((str_nb2[0] != '0' && str_nb1[0] != '0')))
        result = my_strappend_first(result, '-');
    return (result);
}