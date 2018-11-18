/*
** EPITECH PROJECT, 2018
** divide_normfile.c
** File description:
** file for coding style op
*/

#include "../../include/divide.h"

int check_len_div(char *str0, char *str1)
{
    int len0 = 0;
    int len1 = 0;
    int i;

    for (i = 0; str0[i] == '0' || str0[i] == '-'; i++);
    for (int w = i; str0[w] != '\0'; w++, len0++);
    for (i = 0; str1[i] == '0' || str1[i] == '-'; i++);
    for (int w = i; str1[w] != '\0'; w++, len1++);
    if (len0 - len1 >= 6)
        return (1);
    return (0);
}

char *update_to_norm1_div(char *res, char *str, int i)
{
    int w;
    int compt = 0;

    for (int j = i; str[j] != '\0'; j++, compt++);
    res = malloc(compt + 1);
    for (w = 0; w < compt; w++, i++)
        res[w] = str[i];
    res[w] = '\0';
    return (res);
}

char *update_to_norm2_div(char *res, char *str, int i)
{
    int w;
    int compt = 0;

    for (int j = i; str[j] != '\0'; j++, compt++);
    res = malloc(compt + 1);
    for (w = 0; w < compt - 1; w++, i++)
        res[w] = str[i + 1];
    res[w] = '\0';
    return (res);
}
