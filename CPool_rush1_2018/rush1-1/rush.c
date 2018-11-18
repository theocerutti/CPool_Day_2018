/*
** EPITECH PROJECT, 2018
** rush1-1
** File description:
** rush1-1
*/

#include <unistd.h>

void my_putchar(char c);

int handle_errors(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n",14);
        return (1);
    }
    return (0);
}

void display_char(int ac_h, int ac_w, int x, int y)
{
    if ((ac_h == 1 || ac_h == y) && (ac_w == 1 || ac_w == x)) {
        my_putchar('o');
        return;
    }
    if (ac_h == 1 || ac_h == y) {
        my_putchar('-');
        return;
    }
    if (ac_w == 1 || ac_w == x) {
        my_putchar('|');
        return;
    }
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
