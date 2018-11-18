/*
** EPITECH PROJECT, 2018
** infin_mult
** File description:
** infin_mult -- calc
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/func_infin_mult.h"

char **add_nb_to_tab(char **tab, char *result, int nb_result)
{
    int len_zero = 0;
    char *result_without_zero;
    int good_len = 0;
    int j = 0;
    int i = 0;

    for (len_zero = 0; result[len_zero] == '0'; len_zero++);
    good_len = my_strlen(result) - len_zero;
    result_without_zero = malloc(sizeof(char) * good_len);
    if (result_without_zero == NULL)
        exit(84);
    for (j = 0, i = len_zero; result[i] != '\0'; i++, j++)
        result_without_zero[j] = result[i];
    tab[nb_result] = malloc(sizeof(char) * good_len);
    if (tab[nb_result] == NULL)
        exit(84);
    result_without_zero[good_len] = '\0';
    tab[nb_result] = result_without_zero;
    return (tab);
}

char *multi_result(char *result, char *nb1, char *nb2, int j)
{
    char rest = '0';
    int index = my_strlen(result) - 1;
    int num = 0;

    for (int i = my_strlen(nb1) - 1; i >= 0; i--, index--) {
        num = (nb1[i] - '0') * (nb2[j] - '0') - '0' + rest;
        if (num >= 10) {
            rest = num / 10 + '0';
            num %= 10;
            result[index - 1] = rest;
        } else
            rest = '0';
        result[index] = num + '0';
    }
    return (result);
}

char *add_result(char *nb1, char *nb2, char **tab, int nb_result)
{
    char *final_res;

    final_res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 2));
    if (final_res == NULL)
        exit(84);
    for (int i = 0; i != nb_result; i++)
        final_res = infin_add(final_res, tab[i]);
    return (final_res);
}

char *calc_multi(char *nb1, char *nb2, char *result, int param[])
{
    char **tab = malloc(sizeof(char *) * (param[0] + 2));
    int nb_result = 0;
    char *final_res;
    int j = my_strlen(nb1) - 1;
    int i = 0;

    if (tab == NULL)
        exit(84);
    for (int stop = param[0] - 1; stop >= 0 + param[1]; j--, stop--) {
        for (i = 0; i != my_strlen(nb2) + my_strlen(nb1); i++)
            result[i] = '0';
        result[i] = '\0';
        result = multi_result(result, nb1, nb2, j);
        for (int i = 0; i != nb_result; i++)
            result = my_strappend(result, '0');
        tab = add_nb_to_tab(tab, result, nb_result);
        nb_result += 1;
    }
    final_res = add_result(nb1, nb2, tab, nb_result);
    return (final_res);
}

char *transform_str_zero(char *str_nb, int len_1, int len_2)
{
    int diff = len_1 - len_2;

    diff = ABS(diff);
    for (int i = 0; i != diff; i++)
        str_nb = my_strappend_first(str_nb, '0');
    return (str_nb);
}
