/*
** EPITECH PROJECT, 2018
** set_str.c
** File description:
** functions to set str and begin the division
*/

#include "../../include/divide.h"

char *update_str(char sign, char *str, char *res)
{
    int i = 0;

    for (; str[i] == '0'; i++);
    i -= 1;
    str[i] = sign;
    if (sign == '-')
        res = update_to_norm1_div(res, str, i);
    else if (sign == '0')
        res = update_to_norm2_div(res, str, i);
    return (res);
}

char *set_string(char *str, char *str1, char *str2)
{
    int len_ind[3] = {0, 0, 0};

    for (len_ind[0] = 0; str1[len_ind[0]] != '\0'; len_ind[0]++);
    for (len_ind[1] = 0; str2[len_ind[1]] != '\0'; len_ind[1]++);
    if (len_ind[0] < len_ind[1]) {
        str = malloc(len_ind[1] + 1);
        len_ind[2] = 1;
    }
    else if (len_ind[0] > len_ind[1]) {
        str = malloc(len_ind[0] + 1);
        len_ind[2] = 2;
    }
    modify_strings(str, str1, str2, len_ind);
    return (str);
}

void modify_strings(char *str, char *str1, char *str2, int *ind)
{
    int j;

    if (ind[2] == 0)
        launch_div(str1, str2, ind[0]);
    if (ind[2] == 1) {
        for (j = 0; j < ind[1]; j++)
            str[j] = '0';
        str[j] = '\0';
        modify_strings1(str, str2, str1, ind[0]);
        launch_div(str, str2, ind[1]);
    }
    if (ind[2] == 2) {
        for (j = 0; j < ind[0]; j++)
            str[j] = '0';
        str[j] = '\0';
        modify_strings1(str, str1, str2, ind[1]);
        launch_div(str1, str, ind[0]);
    }
}

void modify_strings1(char *str1, char *str2, char *str_sub, int len)
{
    int z = len - 1;
    int len_pos;

    for (len_pos = 0; str2[len_pos] != '\0'; len_pos++);
    for (int i = len_pos - 1; z >= 0; i--, z--) {
        str1[i] = str_sub[z];
        if (str1[i] == '-')
            str1[i] = '0';
    }
}

void no_sign(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '-')
            str1[i] = '0';
        if (str2[i] == '-')
            str2[i] = '0';
    }
}
