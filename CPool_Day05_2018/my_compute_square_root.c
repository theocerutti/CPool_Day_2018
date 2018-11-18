/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    while(i < nb) {
        if (i * i == nb)
            return (i);
        i += 1;
    }
    return (0);
}
