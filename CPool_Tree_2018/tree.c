/*
** EPITECH PROJECT, 2018
** tree
** File description:
** tree
*/

#include <unistd.h>

int get_base(int nb_triangle, int add_tri, int save_star, int *base)
{
    int nb_line = 0;
    int nb_star = 0;
    int add_star = nb_triangle - 1;
    int count_star = 0;
    int ok = 0;

    for (nb_line = 0; nb_line < add_tri + 4; nb_line++) {
        if (nb_line == 0 && add_tri != 0) {
            ok = 0;
            add_star = save_star + 3;
            save_star = 0;
        }
        count_star = 0;
        for (nb_star = add_star; nb_star < nb_triangle + add_tri; nb_star++)
            count_star += 1;
        add_star -= 2;
        if (nb_line == add_tri + 2) {
            ok = 1;
            save_star = add_star;
        }
    }
    if (nb_triangle == add_tri + 1)
        *base = count_star;
    return (save_star);
}

int tree_get_base(int size)
{
    int save_star = 0;
    int base = 0;
    int *p_base = &base;

    for (int i = 0; i < size; i++)
        save_star = get_base(size, i, save_star, p_base);
    return (base);
}

int make_triangle(int nb_triangle, int add_tri, int save_star, int base, int *p_save_space)
{
    int nb_line = 0;
    int space = 1;
    int sup_space = 0;
    int nb_star = 0;
    int add_star = nb_triangle - 1;
    int count_star = 0;
    int ok = 0;
    int add = 0;

    if (base % 2 == 1) {
        base -= 1;
        sup_space = -base/2;
    }
    else
        sup_space = -((base/2)-1);
    for (nb_line = 0; nb_line < add_tri + 4; nb_line++) {
        if (nb_line == 0 && add_tri != 0) {
            ok = 0;
            add_star = save_star + 3;
            save_star = 0;
            sup_space = *p_save_space;
            *p_save_space = 0;
        }
        for (space = sup_space; space < add_tri; space++)
            my_putchar(' ');
        count_star = 0;
        for (nb_star = add_star; nb_star < nb_triangle + add_tri; nb_star++) {
            my_putchar('*');
            count_star += 1;
        }
        my_putchar('\n');
        sup_space += 1;
        add_star -= 2;
        if (nb_line == add_tri + 2) {
            ok = 1;
            save_star = add_star;
            *p_save_space = sup_space;
        }
    }
    return (save_star);
}

void make_log(int i, int size, int base)
{
    int add_pipe = 0;
    int j = 0;
    int space = 0;
    int add = 0;

    if (base % 2 == 1) {
        base -= 1;
        space = base/2;
    }
    else
        space = (base/2) - 1;
    if (size % 2 == 0)
        add = 1;
    for (j = 0; j < space - size/2; j++)
        my_putchar(' ');
    for (add_pipe = 0; add_pipe < size + add; add_pipe++)
        my_putchar('|');
    my_putchar('\n');
}

void tree(int size)
{
    int save_star = 0;
    int save_space = 0;
    int *p_save_space = &save_space;
    int base = 0;

    for (int i = 0; i < size; i++)
        base = tree_get_base(size);
    for (int i = 0; i < size; i++)
        save_star = make_triangle(size, i, save_star, base, p_save_space);
    for (int i = 0; i < size; i++)
        make_log(i, size, base);
}
