/*
** EPITECH PROJECT, 2018
** eval_expr.h
** File description:
** bistromatique
*/

#ifndef __INCLUSION3__
#define __INCLUSION3__

void error_display(char *);
int count_operator(char, char **);
int count_base(char, char **);
void divided_by_zero(char *, char **);
void void_parenthesis(char **, char **);
void operator_error(char **, char **);
void char_error(char *, char **);
void operator_base(char **);
char **basic_operator(int, int, char **, char **);
char **default_calc(int, int, char **, char **);
char **multiply(int, int, char **, char **);
char **parenthesis(char **, char **, int);
int len_tab(char **);
char *evalexpr(char **, char *, int);
char **modify(char *, int, char **);
char **negative_modify(char *, int, char **);
char **negative_parenthesis(char **, int, char **);
char **del_parenthesis(char **, int, int, char **);
char *reverse(char *, int);
char *coperator(char *, char *, char, char **);
char *calc_call(char *, char *, char, char *);
char *negative_str(char *, char *);
int sign_calc(char *, char **, int, int);
char *sign(char *, char **, int);
int condition_operator(char, char **);
int condition_base(char, char **);
char *tab_fill(char **, char *, char **);
int counter(char **, char *);
char **tab_maker(char **, char **, char *);

#endif
