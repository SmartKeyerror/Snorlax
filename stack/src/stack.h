#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct stack {
    size_t size;
    size_t capacity;
    int elements[0];
} Stack;

Stack *new_stack(size_t capacity);

void delete_stack(Stack *stack);

bool is_stack_empty(Stack *stack);

bool is_stack_full(Stack *stack);

int push(Stack *stack, int value);

int pop(Stack *stack, int *value);

#endif
