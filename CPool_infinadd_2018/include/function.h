/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** header of infin_add
*/

#ifndef FUNCTION
#define FUNCTION

#define IF_ZERO_ZERO av[1][0] == '0' && av[2][0] == '0'  && av[1][1] ==  '\0'||\
       ((av[1][1] == '0' && av[2][1] == '0') && (av[1][0] == '-' && \
       av[2][0] == '-')) || \
       ((av[1][1] == '0' && av[2][0] == '0') && (av[1][0] == '-')) || \
       ((av[1][0] == '0' && av[2][1] == '0') && av[2][0] == '-')

char *malloc_result_neg(char *av[], int *p_len_big, char *str_nb1, char *str_nb2);
char *calculate_neg(char *str_nb1, char *str_nb2, char *result, int len_biggest);
char *transform_str_zero_neg(char *str_nb, int len_biggest, int len_1, int len_2);
int look_nb_biggest(char *str_nb1, char *str_nb2);
char *malloc_result(char *av[], int *p_len_big, char *str_nb1, char *str_nb2);
char *calculate(char *str_nb1, char *str_nb2, char *result, int len_biggest);
char *transform_str_zero(char *str_nb, int len_biggest, int len_1, int len_2);
int look_for_minus(char *str_nb1, char *str_nb2);
char *my_strappend_first(char *src, char ch);
void print_result(char *r, char *s1, char *s2);

#endif