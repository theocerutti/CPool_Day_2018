/*
** EPITECH PROJECT, 2018
** infin_add.c
** File description:
** Add 2 number, handle infinite numbers
*/

#include <unistd.h>
#include "include/my.h"
#include "include/function.h"

int look_if_same(char *str_nb1, char *str_nb2)
{
    str_nb1++;
    str_nb2++;
    return (my_strcmp(str_nb1, str_nb2));
}

int infin_add(int ac, char *av[])
{
    int len_biggest = 0;
    int *p_len_big = &len_biggest;
    int len_1 = my_strlen(av[1]);
    int len_2 = my_strlen(av[2]);
    char *result;
    char *str_nb1 = av[1];
    char *str_nb2 = av[2];
    int i = 0;

    result = malloc_result(av, p_len_big, str_nb1, str_nb2);
    if (len_1 > len_2)
        str_nb2 = transform_str_zero(str_nb2, len_biggest, len_1, len_2);
    else if (len_1 < len_2)
        str_nb1 = transform_str_zero(str_nb1, len_biggest, len_1, len_2);
    result = calculate(str_nb1, str_nb2, result, len_biggest);
    print_result(result, str_nb1, str_nb2);
    return (0);
}

int infin_sub(int ac, char *av[], char *result)
{
    int len_biggest = 0;
    int *p_len_big = &len_biggest;
    int len_1 = my_strlen(av[1]);
    int len_2 = my_strlen(av[2]);
    char *str_nb1 = av[1];
    char *str_nb2 = av[2];

    result = malloc_result_neg(av, p_len_big, str_nb1, str_nb2);
    if (len_1 > len_2)
        str_nb2 = transform_str_zero(str_nb2, len_biggest, len_1, len_2);
    else if (len_1 < len_2)
        str_nb1 = transform_str_zero(str_nb1, len_biggest, len_1, len_2);
    if (look_if_same(str_nb1, str_nb2) == 0) {
        my_putchar('0');
        return (0);
    } else if (look_nb_biggest(str_nb1, str_nb2) == 1)
        result = calculate_neg(str_nb1, str_nb2, result, len_biggest);
    else if (look_nb_biggest(str_nb1, str_nb2) == 0) {
        my_putchar('-');
        result = calculate_neg(str_nb2, str_nb1, result, len_biggest);
    }
    print_result(result, str_nb1, str_nb2);
    return (0);
}

int main(int ac, char *av[])
{
    int bool_minus = 0;
    char *result;

    if (ac != 3 || av[1][0] == '\0' && av[2][0] == '\0')
        return (84);
    if (IF_ZERO_ZERO) {
        my_putchar('0');
        return (0);
    }
    bool_minus = look_for_minus(av[1], av[2]);
    if (bool_minus == 1) {
        av[1][0] = '0';
        av[2][0] = '0';
    }
    if (av[1][0] == '-' || av[2][0] == '-')
        infin_sub(ac, av, result);
    else
        infin_add(ac, av);
    return (0);
}
