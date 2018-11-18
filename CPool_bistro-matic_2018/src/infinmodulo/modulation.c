/*
** EPITECH PROJECT, 2018
** division.c
** File description:
** functions to divide
*/

#include "../../include/modulo.h"

char *update_to_norm1(char *res, char *str, int *i)
{
    for (int j = i[0]; str[j] != '\0'; j++, i[1]++);
    res = malloc(i[1] + 1);
    for (int j = 0; j < i[1]; j++, i[0]++) {
        res[j] = str[i[0]];
        res[j + 1] = '\0';
    }
    return (res);
}

int higher_mod(char *str1, char *str2, int len)
{
    int i = 0;
    int j = 0;

    for (; str1[i] == '0'; i++);
    for (; str2[j] == '0'; j++);
    if ((len == i || i == len - 1) && str1[i] < str2[j])
        return (1);
    for (; str1[i] != '\0' && str2[j] != '\0'; i++, j++) {
        if (i > j)
            return (1);
        if ((str1[i] < str2[j] && i == j) && (str1[i - 1] == str2[j - 1]))
            return (1);
    }
    return (0);
}

void infinless_mod(char *str1, char *str2, int len)
{
    int calc;
    int rest = 0;

    for (int i = len - 1; i >= 0; i--) {
        calc = 10 + (str1[i] - 48) - (str2[i] - 48);
        str1[i] = (calc - rest) % 10 + 48;
        if (calc - rest < 10)
            rest = 1;
        else
            rest = 0;
    }
}

void get_res_mod(char *str1, char *str2, int len)
{
    for (int i = 0; i < len; i++)
        str2[i] = str1[i];
}

void launch_div_mod(char *str1, char *str2, int len)
{
    int index = 0;

    no_sign_mod(str1, str2);
    index = higher_mod(str1, str2, len);
    for (int i = 0; index == 0; i++) {
        infinless_mod(str1, str2, len);
        index = higher_mod(str1, str2, len);
    }
    get_res_mod(str1, str2, len);
}
