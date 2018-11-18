/*
** EPITECH PROJECT, 2018
** infnin_add_2.c
** File description:
** bistromatique
*/

#include <stdlib.h>
#include "../../include/add_less.h"

char *negative_restrite(char *result, int a, int len1, int len2)
{
    int len = 0;

    if (a == 1 || a == 0)
        len = len1;
    else
        len = len2;
    result[len + 1] = '\0';
    for (int i = len; i != 1; i--) {
        if (result[i] < 48 || result[i - 1] > 57) {
            result[i - 1] -= 1;
            result[i] += 10;
        }
    }
    return (result);
}

char *negative_calc(char large, char tiny, char *result, int i)
{
    char number;
    char tiny2 = '0';

    if (result[i] == '\0')
        result[i] = '0';
    if (result[i - 1] == '\0')
        result[i - 1] = '0';
    if (tiny >= '0' && tiny <= '9')
        tiny2 = tiny;
    number = (large - tiny2) + '0';
    result[i] = (number - result[i]) + '0';
    return (result);
}

char *negative_process(char *str1, char *str2, char *result, int a)
{
    int len1 = 0;
    int len2 = 0;

    for (len1 = 0; str1[len1] != '\0'; len1++);
    for (len2 = 0; str2[len2] != '\0'; len2++);
    if (a == 1 || a == 0) {
        result = malloc(sizeof(char) * (len1 + 1));
        for (int i = len1 + 1; i != 0; i--) {
            result = negative_calc(str1[i - 2], str2[len2 - 1], result, i - 1);
            len2 = len2 > 0 ? len2 - 1 : 0;
        }
    } else {
        result = malloc(sizeof(char) * (len2 + 1));
        for (int i = len2 + 1; i != 0; i--) {
            result = negative_calc(str2[i - 2], str1[len1 - 1], result, i - 1);
            len1 = len1 > 0 ? len1 - 1 : 0;
        }
    }
    result = negative_restrite(result, a, len1, len2);
    return (result);
}

int negative_number(char *str1, char *str2)
{
    int s1;
    int s2;
    int a = 0;

    for (s1 = 0; str1[s1] != '\0'; s1++);
    for (s2 = 0; str2[s2] != '\0'; s2++);
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] > str2[i] && a == 0 && s1 >= s2)
            a = 1;
        else if (str2[i] > str1[i] && a == 0 && s2 >= s1)
            a = 2;
    }
    return (a);
}

char *negative_main(char **argv, char *result, char *str1, char*str2)
{
    int a = 0;

    if (str1[0] == '-')
        str1++;
    else
        str2++;
    a = negative_number(str1, str2);
    result = negative_process(str1, str2, result, a);
    result[0] = '0';
    if (result[1] == '0')
        result++;
    if (a == 1 && argv[1][0] == '-')
        result[0] = '-';
    else if (a == 2 && argv[2][0] == '-')
        result[0] = '-';
    else
        result++;
    if (result[0] == '\0')
        result[0] = '0';
    return (result);
}
