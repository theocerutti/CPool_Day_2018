/*
** EPITECH PROJECT, 2018
** stack header
** File description:
** stack header
*/

#ifndef _STACK_
#define _STACK_

struct stack_struct {
    int index;
    int size;
    int *value;
};

struct stack_struct *create_stack(int size);
void push(struct stack_struct *stack, int nb);
int pop(struct stack_struct *stack);
int is_empty(struct stack_struct *stack);
int peek(struct stack_struct *stack);

#endif