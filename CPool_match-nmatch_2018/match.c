/*
** EPITECH PROJECT, 2018
** match.c
** File description:
** find out if two strings match
*/

#include <stdlib.h>
#include "include/my.h"

char *supp_star(char const *s2, char *s3)
{
    int bool = 0;
    int k = 0;

    for (int i = 0; s2[i] != '\0'; i++) {
        if (s2[i] == '*' && bool == 0) {
            s3[k] = '*';
            bool = 1;
            k += 1;
        }
        else if (s2[i] != '*') {
            s3[k] = s2[i];
            k += 1;
            bool = 0;
        }
    }
    s3[k] = '\0';
    return (s3);
}

int check_match(char const *s1, char *s3, int len_s1, int len_s3)
{
    int j = 0;
    int count = 0;

    for (int i = 0; s3[i] != '\0'; i++) {
        if (s1[j] == s3[i] && j == len_s1 - 1 && i == len_s3 - 1)
            return (1);
        if (s3[len_s3] == s1[len_s1] && s3[0] == '*')
            return (1);
        if (s3[i] == '*') {
            while (s3[i + 1] != s1[j]) {
                j += 1;
                if (j > len_s1)
                    return (0);
            }
        }
        if (s1[j] == '\0')
            return (1);
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s3[i])
            count += 1;
    }
    if (count == len_s1)
        return (1);
    return (0);
}

int match(char const *s1, char const *s2)
{
    int len_s1 = 0;
    int len_s2 = 0;
    int len_s3 = 0;
    char *s3 = NULL;
    int is_match = 0;

    for (len_s1 = 0; s1[len_s1] != '\0'; len_s1++)
    for (len_s2 = 0; s2[len_s2] != '\0'; len_s2++)
    len_s3 = len_s2;
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s2[i] == '*' && s2[i + 1] == '*')
            len_s3 -= 1;
    }
    s3 = malloc(len_s3 + 1);
    s3 = supp_star(s2, s3);
    for (len_s3 = 0; s3[len_s3] != '\0'; len_s3++);
    is_match = check_match(s1, s3, len_s1, len_s3);
    return (is_match);
}
