/*
** EPITECH PROJECT, 2018
** test_my_strcpy
** File description:
** test01
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, copy_string_in_empty_array)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test (my_strcpy, copy_string_in_empty_array_return_value)
{
    char dest[6] = {0} ;
    char *copy = my_strcpy(dest, "Hello");

    cr_assert_str_eq(copy, "Hello");
}
