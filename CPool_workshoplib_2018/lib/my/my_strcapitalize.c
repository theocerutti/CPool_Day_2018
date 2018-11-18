/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;

    str = my_strlowcase(str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        if (((str[i] < 'a' || str[i] > 'z') && \
           (str[i] < 'A' || str[i] > 'Z')) &&  \
           (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
            str[i + 1] -= 32;
    }
    return (str);
}