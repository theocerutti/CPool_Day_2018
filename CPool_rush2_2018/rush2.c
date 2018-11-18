/*
** EPITECH PROJECT, 2018
** rush2_step3
** File description:
** rush2
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}

void print_result(char stock, int count, int pourcent, int nb_commas)
{
    my_putchar(stock);
    my_putchar(':');
    my_put_nbr(count);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(pourcent);
    my_putchar('.');
    if (nb_commas == 0)
        my_put_nbr(0);
    my_put_nbr(nb_commas);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

int count_nb_total(char *str_low)
{
    int nb_total_letter = 0;

    for (int len = 0; str_low[len] != '\0'; len++) {
        if ((str_low[len] >= 'a' && str_low[len] <= 'z') \
            || (str_low[len] >= 'A' && str_low[len] <= 'Z'))
            nb_total_letter += 1;
    }
    return (nb_total_letter);
}

void counter(char *str_low, char *argv[], int argc)
{
    float count = 0;
    char *letter_low;
    char stock;
    float nb_total_letter = 0;
    float pourcent = 0;
    int nb_commas = 0;

    nb_total_letter = count_nb_total(str_low);
    for (int j = 2; j != argc; j++) {
        stock = argv[j][0];
        letter_low = my_strlowcase(argv[j]);
        count = 0;
        for (int i = 0; str_low[i] != '\0'; i++)
            if (str_low[i] == letter_low[0])
                count += 1;
        pourcent = (count/nb_total_letter) * 100;
        nb_commas = (pourcent * 100);
        nb_commas = (int)nb_commas % 100;
        if (str_low[0] == '\0') {
            count = 0;
            pourcent = 0;
            nb_commas = 0;
        }
        print_result(stock, count, pourcent, nb_commas);
    }
}

int main(int argc, char *argv[])
{
    char *str_low = my_strlowcase(argv[1]);

    for (int i = 2; i != argc; i++) {
        if ((argv[i][0] < 'a' || argv[i][0] > 'z') &&\
        (argv[i][0] < 'A' || argv[i][0] > 'Z'))
            return (84);
    }
    counter(str_low, argv, argc);
    return (0);
}
