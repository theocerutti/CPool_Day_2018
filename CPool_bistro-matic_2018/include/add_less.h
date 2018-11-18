/*
** EPITECH PROJECT, 2018
** header add_less
** File description:
** header add_less
*/

#define CONDITION ((s1[1] == '\0' && s2[0] == '\0') || \
                  (s1[0] == '\0' && s2[1] == '\0')) && \
                  (s1[0] == '\0' || s1[0] == '-') && \
                  (s2[0] == '\0' || s2[0] == '-')

char *negative_restrite(char *, int, int, int);
char *negative_calc(char, char, char *, int);
char *negative_process(char *, char *, char *, int);
int negative_number(char *, char *);
char *negative_main(char **, char *, char *, char *);
char *restrite(char *, int);
char *calc(char, char, char *, int);
char *process(char *, char *, char *);
char *pre_process(char **, char *, char *, char *);
char *add_less(char *, char *);
