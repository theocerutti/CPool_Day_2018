/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Day 03 -- task07
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + '0');
        return (0);
    }
    if (nb < 0) {
        if (nb <= 0 && nb >= -9) {
            my_putchar('-');
            my_putchar((nb + '0') - nb * 2);
            return (0);
        }
        my_put_nbr(nb / 10);
        my_putchar(((nb % 10) + '0') - (nb % 10) * 2);
        return (0);
    }
    my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return (0);
}
