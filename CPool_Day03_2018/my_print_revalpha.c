/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** task02
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for(char i = 122; i > 96; i--)
        my_putchar(i);
    return (0);
}
