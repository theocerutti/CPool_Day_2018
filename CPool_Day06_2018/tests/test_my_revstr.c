/*
** EPITECH PROJECT, 2018
** test_my_revstr.c
** File description:
** task03.5
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test (my_revstr, return_value_is_reversed)
{
    char str[] = "Hello";
    cr_assert_str_eq(my_revstr(str), "olleH");
}
