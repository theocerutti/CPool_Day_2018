/*
** EPITECH PROJECT, 2018
** strlowcase
** File description:
** task08
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}
