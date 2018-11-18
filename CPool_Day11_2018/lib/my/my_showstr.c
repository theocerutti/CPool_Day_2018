/*
** EPITECH PROJECT, 2018
** my_showstr
** File description:
** Day08 -- my_showstr
*/

void my_putchar(char c);

void get_hexa(int s)
{
    char hexa_tab[] = "0123456789abcdef";
    int j = 0;
    int k = 0;
    int i;
    char hexa[2];

    for (i = 0; i < 16; i++) {
        if (16 * k < s && 16 * (k + 1) < s)
            k += 1;
        else if (16 * k + j < s)
            j += 1;
    }
    hexa[2] = hexa_tab[k];
    hexa[1] = hexa_tab[j];
    my_putchar(hexa[2]);
    my_putchar(hexa[1]);
}

int my_showstr(char const *str)
{
    int i = 0;
    int s = 0;

    for (i = 0; str[i] != '\0'; i++) {
        s = str[i];
        if (s < 32) {
            my_putchar('\\');
            get_hexa(s);
        } else
            my_putchar(str[i]);
    }
    return (0);
}
