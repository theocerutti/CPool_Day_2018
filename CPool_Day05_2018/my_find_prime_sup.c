/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** Day05 -- task07
*/

int my_is_primee(int nb)
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

int my_find_prime_sup(int nb)
{
    int bool_e = my_is_primee(nb);
    int j = 0;
    int count = 0;
    int i;
    int n_mod;

    if (bool_e == 1)
        return (nb);
    while (j != 1) {
        if (my_is_primee(nb) == 1)
            return (nb);
        if (nb == 1 || nb == 0) {
            j = 1;
            break;
        }
        for (i = 2; i < nb; i++) {
            n_mod = nb % i;
            if (n_mod == 0)
                count += 1;
        }
        nb -= 1;
    }
    return (nb);
}
