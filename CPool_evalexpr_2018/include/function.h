/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** header of infin_add
*/

#ifndef FUNCTION
#define FUNCTION

char *my_strdelete(char *src, int ch_to_delete);
char *malloc_without_space(char const *expr);
int take_priority(char op);
int is_less_priority(char operator, char operator_stack);
int operation(int nb1, int nb2, char op);
char *supp_zero(char *str);

#endif
