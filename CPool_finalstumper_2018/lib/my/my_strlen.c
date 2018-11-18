/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int count = 0;

    for (count = 0; str[count] != '\0'; count++);
    return (count);
}
