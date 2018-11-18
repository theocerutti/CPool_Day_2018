/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** task01
*/

void my_putchar(char c);

int my_print_alpha(void)
{    
    for(char c = 97; c < 123; c++)
        my_putchar(c);
    return (0);
}
