/*
** EPITECH PROJECT, 2018
** tests_run
** File description:
** task02 -- Day12
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int cat(int ac, char *av[]);

char *tab[] = {"cat", "../tests/empty", "../tests/3", "../tests/1"};
char *tab2[] = {"cat"};
char *empty_file[] = {"../tests/empty"};

Test (cat, empty_file_need_to_return_0)
{
    cr_assert_eq(0, cat(1, empty_file));
}

Test (cat, more_than_one_file)
{
    cr_assert_eq(0, cat(4, tab));
}

Test (cat, zero_parameters)
{
    cr_assert_eq(0, cat(0, tab2));
}
