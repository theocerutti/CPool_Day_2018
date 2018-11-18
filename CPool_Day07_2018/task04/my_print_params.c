/*
** EPITECH PROJECT, 2018
** my_print_params
** File description:
** Day07 -- task04
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_print_params(char const *param)
{
    for (int i = 0; param[i] != '\0'; i++)
        my_putchar(param[i]);
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_print_params(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
