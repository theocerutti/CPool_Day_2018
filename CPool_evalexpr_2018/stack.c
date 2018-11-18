/*
** EPITECH PROJECT, 2018
** stack managers
** File description:
** stack managers
*/

#include <stdlib.h>
#include "include/stack.h"

struct stack_struct *create_stack(int size_param)
{
    struct stack_struct *stack = malloc(sizeof(struct stack_struct));

    stack->size = size_param;
    stack->index = -1;
    stack->value = malloc(stack->size * sizeof(int));
    return (stack);
}

void push(struct stack_struct *stack, int nb)
{
    stack->index++;
    stack->value[stack->index] = nb;
}

int pop(struct stack_struct *stack)
{
    int nb_stack = 0;

    if (is_empty(stack) != 1) {
        nb_stack = stack->value[stack->index];
        stack->index--;
    }
    return (nb_stack);
}

int peek(struct stack_struct *stack)
{
    int nb_stack = 0;
    int index_temp = 0;

    if (is_empty(stack) != 1) {
        index_temp = stack->index;
        nb_stack = stack->value[index_temp];
    }
    return (nb_stack);
}

int is_empty(struct stack_struct *stack)
{
    if (stack->index == -1)
        return (1);
    else
        return (0);
}
