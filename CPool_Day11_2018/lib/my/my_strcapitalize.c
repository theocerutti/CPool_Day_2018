/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[0] >= 97 && str[0] <= 122)
            str[0] -= 32;
        if (str[i] == 32 && str[i + 1] >= 97 && str[i + 1] <= 122)
            str[i + 1] -= 32;
    }
    return (str);
}
