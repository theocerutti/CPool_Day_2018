/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** my_strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int k = 0;
    int l_to_find = 0;
    int l_str = 0;

    for (l_to_find = 0; to_find[l_to_find] != '\0'; l_to_find++);
    for (l_str = 0; str[l_str] != '\0'; l_str++) {
        if (to_find[j] == str[l_str] && j != l_to_find) {
            j += 1;
            k = l_str;
        }
        else if (j != 0 && to_find[j - 1] != str[l_str] && j != l_to_find) {
            j = 0;
            k = 0;
        }
    }
    if (j == l_to_find)
        return (str + k - j + 1);
    return (0);
}
