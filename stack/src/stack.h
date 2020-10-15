#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct stack {
    size_t size;
    size_t capacity;
    size_t element_size;
    void *elements;
} Stack;

Stack *new_stack(size_t capacity, size_t element_size);

void delete_stack(Stack *stack);

bool is_stack_empty(Stack *stack);

bool is_stack_full(Stack *stack);

int push(Stack *stack, void *value);

int pop(Stack *stack, void *value);

#endif
