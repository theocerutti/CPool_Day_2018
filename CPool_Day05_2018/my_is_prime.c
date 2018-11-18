/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int count = 0;
    int i;
    int n_mod;

    if (nb == 1 || nb == 0 || nb < 0)
        return (0);
    for (i = 2; i < nb; i++) {
        n_mod = nb % i;
        if (n_mod == 0)
            count += 1;
    }
    if (count != 0)
        return (0);
    return (1);
}
