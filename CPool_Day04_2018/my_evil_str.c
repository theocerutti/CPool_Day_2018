/*
** EPITECH PROJECT, 2018
** my_evil_str
** File description:
** task04
*/

#include <stdio.h>

char *my_evil_str(char *str)
{
    int len = 0;
    int i = 0;
    int j = 0;
    char stock = 0;
    int len2 = 0;

    for (len = 0; str[len] != '\0'; len++)
        len2 += 1;
    for (i = len; i > len2/2; i--) {
        stock = str[j];
        str[j] = str[len - 1];
        str[len - 1] = stock;
        j += 1;
        len -= 1;
    }
    return (str);
}

int main(void)
{
    char str[] = "bojour";
    char *reverse;

    reverse = my_evil_str(str);
    printf("%s", str);
    return(0);
}
