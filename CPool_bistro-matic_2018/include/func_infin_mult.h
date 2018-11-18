/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** header of infin_add
*/

#ifndef __INCLUDE4__
#define __INCLUDE4__

#define ABS(value) (value < 0) ? value * -1 : value

char *multi_result(char *result, char *nb1, char *nb2, int j);
char *my_strappend(char *src, char ch);
char *calc_multi(char *nb1, char *nb2, char *result, int param[]);
char *transform_str_zero(char *str_nb, int len_1, int len_2);
char *my_strdelete(char *src, int ch_to_delete);
char *my_strappend_first(char *src, char ch);
char *infin_add(char *str_nb1, char *str_nb2);
int look_if_same(char *str_nb1, char *str_nb2);
char *calculate(char *str_nb1, char *str_nb2, char *result, int len_biggest);
char *malloc_result(int *p_len_big, char *str_nb1, char *str_nb2);
char *transform_str_zero_add(char *str_nb, int len_1, int len_2);
char *is_calc_neg(char *str_nb, int *p_isneg);
int *assign_var(int len, int var);
char *calc_result(char *nb1, char *nb2, char *result);
char *infin_multi(char *str_nb1, char *str_nb2);

#endif
