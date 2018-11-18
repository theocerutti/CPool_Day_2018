/*
** EPITECH PROJECT, 2018
** my_rev_params
** File description:
** Day07 -- task05
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_rev_params(char const *param)
{
    for (int i = 0; param[i] != '\0'; i++)
        my_putchar(param[i]);
}

int main(int argc, char const *argv[])
{
    int i = 0;

    for (i = argc - 1; i != -1; i--) {
        my_rev_params(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
