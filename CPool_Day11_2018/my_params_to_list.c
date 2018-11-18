/*
** EPITECH PROJECT, 2018
** my_params_to_list.c
** File description:
** Task01 -- Day11
*/

#include <stdlib.h>
#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    int i = 0;
    linked_list_t *liste = NULL;
    linked_list_t *tmp;

    for (i = 0; i < ac; i++) {
        tmp = liste;
        linked_list_t *liste = malloc(sizeof(linked_list_t));
        liste->data = av[i];
        liste->next = tmp;
    }
    return (liste);
}
