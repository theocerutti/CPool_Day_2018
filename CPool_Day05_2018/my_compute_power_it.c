/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int i = 0;
    int result = 1;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    else
        for (i = 0; i < p; i++)
            result *= nb;
    return (result);
}
