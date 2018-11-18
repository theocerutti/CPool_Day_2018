/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** Day05 -- task07
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int is_prime = my_is_prime(nb);
    int count = 0;
    int i = 0;
    int n_mod;

    if (is_prime == 1)
        return (nb);
    while (1) {
        if (my_is_prime(nb) == 1 || nb == 0)
            return (nb);
        for (i = 2; i < nb; i++) {
            n_mod = nb % i;
            if (n_mod == 0)
                count += 1;
        }
        nb -= 1;
    }
    return (nb);
}
