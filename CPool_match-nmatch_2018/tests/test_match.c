/*
** EPITECH PROJECT, 2018
** match test
** File description:
** test
*/

#include <criterion/criterion.h>

int match(char const *s1, char const *s2);

char s1[] = "bonjourjesuis";

Test (match, test01)
{
    char str01[] = "b*";
    cr_assert_eq(1, match(s1, str01));
}

Test (match, test02)
{
    char str02[] = "*s";
    cr_assert_eq(1, match(s1, str02));
}

Test (match, test03)
{
    char str03[] = "*r*";
    cr_assert_eq(1, match(s1, str03));
}

Test (match, test04)
{
    char str04[] = "bon*je*";
    cr_assert_eq(1, match(s1, str04));
}

Test (match, test05)
{
    char str05[] = "*r*s";
    cr_assert_eq(1, match(s1, str05));
}

Test (match, test06)
{
    char str06[] = "z";
    cr_assert_eq(0, match(s1, str06));
}

Test (match, test07)
{
    char str07[] = "b*i";
    cr_assert_eq(0, match(s1, str07));
}

Test (match, test08)
{
    char str08[] = "bonjourjenesuispas";
    cr_assert_eq(0, match(s1, str08));
}

Test (match, test09)
{
    char str09[] = "bonjour*suiss";
    cr_assert_eq(0, match(s1, str09));
}
