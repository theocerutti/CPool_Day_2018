/*
** EPITECH PROJECT, 2018
** cat.c
** File description:
** cat in program
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int cat(int ac, char *av[])
{
    char text[30000];
    int file;
    int size = 0;

    for (int i = 1; i < ac; i++) {
        for (int j = 0; j < 30000; j++)
            text[j] = 0;
        file = open(av[i], O_RDONLY);
        if (file == -1) {
            return (84);
        }
        size = read(file, text, 29999);
        if (size > 1)
            write(1, text, size);
        close(file);
    }
    return (0);
}
