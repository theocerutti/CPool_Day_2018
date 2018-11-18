/*
** EPITECH PROJECT, 2018
** division.c
** File description:
** functions to divide
*/

#include "../../include/divide.h"

int higher(char *str1, char *str2, int len)
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

void infinless(char *str1, char *str2, int len)
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

void infinadd(char *str1, char const *str2, int len)
{
    int calc;
    int rest = 0;

    for (int w = len - 1; w >= 0; w--) {
        calc = str1[w] - 48 + str2[w] - 48;
        str1[w] = (calc + rest) % 10 + 48;
        if (calc + rest > 9)
            rest = 1;
        else
            rest = 0;
    }
}

void get_res(char *str1, char *str2, char *res, int len)
{
    for (int i = 0; i < len; i++) {
        str1[i] = res[i];
        str2[i] = res[i];
    }
}

void launch_div(char *str1, char *str2, int len)
{
    char *str[2];
    int index[2] = {0, 0};

    str[0] = malloc(len + 1);
    str[1] = malloc(len + 1);
    for (index[1] = 0; index[1] < len; index[1]++) {
        str[0][index[1]] = '0';
        str[1][index[1]] = '0';
    }
    str[1][index[1] - 1] = '1';
    str[0][index[1]] = '\0';
    str[1][index[1]] = '\0';
    no_sign(str1, str2);
    index[0] = higher(str1, str2, len);
    for (int i = 0; index[0] == 0; i++) {
        infinless(str1, str2, len);
        infinadd(str[0], str[1], len);
        index[0] = higher(str1, str2, len);
    }
    get_res(str1, str2, str[0], len);
}
