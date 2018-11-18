/*
** EPITECH PROJECT, 2018
** rush1-3
** File description:
** rush1-3
*/

#include <unistd.h>

void my_putchar(char c);

int handle_errors(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 14);
        return (1);
    }
    return (0);
}

void display_char(int h, int w, int x, int y)
{
    if ((h == 1 || h == y) && (w == 1 || w == x) && x > 1 && y > 1) {
        if ((h == 1 && w == 1) || (w == x && h == 1))
            my_putchar('A');
        else
            my_putchar('C');
    }
    else if (h == 1 || h == y || w == 1 || w == x)
        my_putchar('B');
    else
        my_putchar(' ');
}

void rush(int x, int y)
{
    int bool_size = handle_errors(x, y);

    for (int ac_h = 1; ac_h <= y && bool_size == 0; ac_h++) {
        for (int ac_w = 1; ac_w <= x; ac_w++) {
            display_char(ac_h, ac_w, x, y);
        }
        my_putchar('\n');
    }
}
