/*
** EPITECH PROJECT, 2018
** cat
** File description:
** task01 -- Day12
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "cat.c"

int main(int ac, char *av[])
{
    return (cat(ac, av));
}

