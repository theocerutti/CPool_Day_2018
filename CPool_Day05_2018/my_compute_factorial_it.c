/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** task01
*/

int my_compute_factorial_it(int nb)
{
    int i = 0;
    int result = nb;

    if (nb < 0 || nb > 12)
        return (0);
    else if (nb == 0)
        return (1);
    else if (nb > 0)
        for (i = nb - 1; i > 0; i--)
            result *= i;
    return (result);
}
