/*
** EPITECH PROJECT, 2018
** infiniAdd
** File description:
** start bistromatique
*/

#include <stdlib.h>
#include "../../include/add_less.h"

char *restrite(char *result, int i)
{
    if (i == 0)
        return (result);
    if (result[i] >= 58) {
        result[i - 1] += 1;
        result[i] -= 10;
    }
    restrite(result, i - 1);
    return (result);
}

char *calc(char large, char tiny, char *result, int i)
{
    char number;
    char tiny2 = '0';

    if (result[i] == '\0')
        result[i] = '0';
    if (result[i - 1] == '\0')
        result[i - 1] = '0';
    if (tiny >= '0' && tiny <= '9')
        tiny2 = tiny;
    number = (large + tiny2) - 48;
    result[i] = (result[i] + number) - 48;
    if (result[i] >= 58)
      restrite(result, i);
    return (result);
}

char *process(char *str1, char *str2, char *result)
{
    int len1 = 0;
    int len2 = 0;

    for (len1 = 0; str1[len1] != '\0'; len1++);
    for (len2 = 0; str2[len2] != '\0'; len2++);
    if (len1 >= len2) {
        result = malloc(sizeof(char) * (len1 + 2));
        for (int i = len1 + 2; i != 2; i--) {
            result = calc(str1[i - 3], str2[len2 - 1], result, i - 1);
            len2 = len2 > 0 ? len2 - 1 : 0;
        }
    } else {
        result = malloc(sizeof(char) * (len2 + 2));
        for (int i = len2 + 2; i != 2; i--) {
            result = calc(str2[i - 3], str1[len1 - 1], result, i - 1);
            len1 = len1 > 0 ? len1 - 1 : 0;
        }
    }
    return (result);
}

char *pre_process(char **save, char *result, char *str1, char *str2)
{
    if (str1[0] == '-' && str2[0] == '-') {
        str1++;
        str2++;
    } else if (str1[0] == '-' || str2[0] == '-')
        return (negative_main(save, result, str1, str2));
    result = process(str1, str2, result);
    result[0] = '0';
    if (result[1] == '0')
        result++;
    if (save[1][0] == '-' && save[2][0] == '-')
       result[0] = '-';
    else
        result++;
    if (result[0] == '\0')
        result[0] = '0';
    if (result[0] == '-' && result[1] == '\0')
        result[0] = '0';
    return (result);
}

char *add_less(char *s1, char *s2)
{
    char *result = "0";
    char **save = malloc(sizeof(*save) * 2);

    save[1] = s1;
    save[2] = s2;
    for (int i = 0; s1[i] == '0' || s1[i] == '-'; s1++);
    if (save[1][0] == '-') {
        s1--;
        s1[0] = '-';
    }
    for (int i = 0; s2[i] == '0' || s2[i] == '-'; s2++);
    if (save[2][0] == '-') {
        s2--;
        s2[0] = '-';
    }
    if (CONDITION)
        return (result);
    else
        return (pre_process(save, result, s1, s2));
}