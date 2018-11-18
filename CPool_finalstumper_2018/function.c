/*
** EPITECH PROJECT, 2018
** function.c
** File description:
** function.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

void calc_w_h(char *str, int *p_width, int *p_height)
{
    for (int i = 0; str[i] != '\n'; i++)
        *p_width += 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            *p_height += 1;
    }
}

void print_result(int num, int height, int width, int *p_count)
{
    if (height != 0 && width != 0) {
        if (*p_count != 0)
            my_putstr(" || ");
        my_putstr("[rush1-");
        my_put_nbr(num);
        my_putstr("] ");
        my_put_nbr(width);
        my_putchar(' ');
        my_put_nbr(height);
    }
}

int check(char *str, char *pattern, int w, int h)
{
    int count = 0;

    w -= 1;
    h -= 1;
    if (w != 0 && h != 0) {
        if (str[w] != pattern[0])
            return (0);
    } else if (str[w] != pattern[2])
        return (0);
    if (h != 0) {
        for (int i = 1; str[i] != '\0'; i++) {
            if (str[i] == '\n')
                count += 1;
            if (count == h && str[i + 1] == pattern[1] && str[i + 2] != '\n') {
                return (1);
            }
        }
    }
}

int rush3(char *str)
{
    int w = 0;
    int h = 0;
    int count = 0;

    calc_w_h(str, &w, &h);
    check(str, "ooo", w, h) ? print_result(1, h, w, &count), count += 1 : 0;
    check(str, "\\\\*", w, h) ? print_result(2, h, w, &count), count += 1 : 0;
    check(str, "ACB", w, h) ? print_result(3, h, w, &count), count += 1 : 0;
    check(str, "CAB", w, h) ? print_result(4, h, w, &count), count += 1 : 0;
    check(str, "CCB", w, h) ? print_result(5, h, w, &count), count += 1 : 0;
    return (0);
}
