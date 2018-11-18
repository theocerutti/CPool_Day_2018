/*
** EPITECH PROJECT, 2018
** divide.c
** File description:
** divide operator
*/

#include "../../include/modulo.h"

char result_isneg_mod(char *, char *);

int check_len_mod(char *, char *);

char *modulo(char *str1, char *str2)
{
    char *res = NULL;
    char *str = NULL;
    int len[2] = {0, 0};
    char sign = result_isneg_mod(str1, str2);

    for (len[0] = 0; str1[len[0]] != '\0'; len[0]++);
    for (len[1] = 0; str2[len[1]] != '\0'; len[1]++);
    if (diviser_higher_mod(str1, str2) == 1)
        return (str1);
    if (check_len_mod(str1, str2) == 1)
        return ("0");
    no_sign_mod(str1, str2);
    str = set_string_mod(str, str1, str2);
    if (len[0] > len[1])
        res = update_str_mod(sign, str1, res);
    else
        res = update_str_mod(sign, str2, res);
    if (res[0] == '-' && res[1] == '\0')
        return ("0");
    return (res);
}

int diviser_higher_mod(char *str1, char *str2)
{
    int index[5] = {0, 0, 0, 0, 0};

    for (; str1[index[0]] == '0' || str1[index[0]] == '-'; index[0]++);
    for (; str2[index[1]] == '0' || str2[index[1]] == '-'; index[1]++);
    for (int w = index[0]; str1[w] != '\0'; index[2]++, w++);
    for (int w = index[1]; str2[w] != '\0'; index[3]++, w++);
    while (index[2] == index[3] && str1[index[0]] != '\0') {
        if (str1[index[0]] > str2[index[0]])
            return (0);
        else if (str1[index[0]] == str2[index[0]])
            index[0] += 1;
        if (str1[index[0]] < str2[index[0]])
            return (1);
    }
    if (index[2] < index[3])
        return (1);
    return (0);
}

char result_isneg_mod(char *str1, char *str2)
{
    if (str1[0] == '-' || (str1[0] == '-' && str2[0] == '-'))
        return ('-');
    else if (str2[0] == '-')
        return ('0');
    return ('0');
}

char *update_to_norm2(char *res, char *str, int *i)
{
    for (int j = i[0]; str[j] != '\0'; j++, i[1]++);
    res = malloc(i[1]);
    for (int j = 0; j < i[1] - 1; j++, i[0]++) {
        res[j] = str[i[0] + 1];
        res[j + 1] = '\0';
    }
    return (res);
}

int check_len_mod(char *str0, char *str1)
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
