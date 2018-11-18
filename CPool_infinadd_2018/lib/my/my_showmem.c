/*
** EPITECH PROJECT, 2018
** my_showmem
** File description:
** Day 06 -- task018
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str);

int my_putnbr_base(int nb, char const *base);

int my_strlen(char const *str);

void print_first_col(int i)
{
    int nb_chiffre = 0;

    if (i == 0)
        nb_chiffre = 2;
    for (int nb_temp = i; nb_temp > 0; nb_temp /= 16)
        nb_chiffre += 1;
    for (int put_zero = 0; put_zero != 8 - nb_chiffre; put_zero++)
        my_putchar('0');
    my_putnbr_base(i, "0123456789abcdef");
    my_putstr(":  ");
}

void print_second_col(char const *str, int i)
{
    for (int j = 0; j < 16; j++) {
        if (j % 2 == 0 && j != 0)
            my_putchar(' ');
        my_putnbr_base(str[j + i], "0123456789abcdef");
    }
    my_putchar(' ');
}

int my_showmem(char const *str, int size)
{
    int len_str = my_strlen(str);

    for (int i = 0; size != 0; i += 16, size--) {
        print_first_col(i);
        print_second_col(str, i);
        for (int r = 0; r < 16; r++) {
            if (r + i > len_str || (str[r] < 30 && str[r] > 127))
                my_putchar('.');
            else if (str[r + i] >= 30 || str[r + i] <= 127) {
                my_putchar(str[r + i]);
            }
        }
        my_putchar('\n');
    }
    return (0);
}
