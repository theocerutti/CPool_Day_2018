/*
** EPITECH PROJECT, 2018
** divide.c
** File description:
** divide operator
*/

#include "../../include/divide.h"

char result_isneg(char *, char *);

char *divide(char *str1, char *str2)
{
    char *res = NULL;
    char *str = NULL;
    int len[2] = {0, 0};
    char sign = result_isneg(str1, str2);

    for (len[0] = 0; str1[len[0]] != '\0'; len[0]++);
    for (len[1] = 0; str2[len[1]] != '\0'; len[1]++);
    if (diviser_higher(str1, str2) == 1)
        return ("0");
    if (check_len_div(str1, str2) == 1)
        return ("0");
    str = set_string(str, str1, str2);
    if (len[0] > len[1])
        res = update_str(sign, str1, res);
    else
        res = update_str(sign, str2, res);
    if (res[0] == '-' && res[1] == '\0')
        return ("0");
    return (res);
}

int diviser_higher(char *str1, char *str2)
{
    int index[4] = {0, 0, 0, 0};

    for (; str1[index[0]] == '0' || str1[index[0]] == '-'; index[0]++);
    for (; str2[index[1]] == '0' || str2[index[1]] == '-'; index[1]++);
    for (int w = index[0]; str1[w] != '\0'; index[2]++, w++);
    for (int w = index[1]; str2[w] != '\0'; index[3]++, w++);
    while (index[2] == index[3] && str1[index[0]] != '\0') {
        if (str1[index[0]] > str2[index[0]])
            return (0);
        if (str1[index[0]] == str2[index[0]])
            index[0] += 1;
        if (str1[index[0]] < str2[index[0]])
            return (1);
    }
    if (index[2] < index[3])
        return (1);
    return (0);
}

char result_isneg(char *str1, char *str2)
{
    if ((str1[0] == '-' && str2[0] != '-') || (str1[0] \
       != '-' && str2[0] == '-')) {
        if (str1[0] == '-')
            str1[0] = '0';
        if (str2[0] == '-')
            str2[0] = '0';
        return ('-');
    }
    return ('0');
}
