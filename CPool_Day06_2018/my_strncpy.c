/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_src = 0;

    for (len_src = 0; src[len_src] != '\0'; len_src++);
    if (n > len_src)
        return (0);
    for (i = 0; i != n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
