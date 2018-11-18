/*
** EPITECH PROJECT, 2018
** stack header
** File description:
** stack header
*/

#ifndef _STACK_
#define _STACK_

struct Stack {
    int index;
    int size;
    int *value;
};

struct Stack *create_stack(int size);
void push(struct Stack *stack, int nb);
int pop(struct Stack *stack);
int is_empty(struct Stack *stack);
int is_full(struct Stack *stack);
int peek(struct Stack *stack);

#endif