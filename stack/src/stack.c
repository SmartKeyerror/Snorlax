#include "stack.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#define SUCCESS 0
#define FAIL -1

Stack *new_stack(size_t capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack) + capacity * sizeof(int));

    stack->size = 0;
    stack->capacity = capacity;

    if (stack == NULL) {
        perror("malloc Stacki failed");
        return NULL;
    }

    return stack;
}

void delete_stack(Stack *stack) {
    free(stack);
}

bool is_stack_empty(Stack *stack) {
    return (stack->size == 0);
}

bool is_stack_full(Stack *stack) {
    return (stack->size >= stack->capacity);
}

int push(Stack *stack, int value) {
    if (is_stack_full(stack))
        return FAIL;
    
    stack->elements[stack->size] = value;
    stack->size++;

    return SUCCESS;
}

int pop(Stack *stack, int *value) {
    if (is_stack_empty(stack))
        return FAIL;
    
    *value = stack->elements[stack->size - 1];
    stack->size--;

    return SUCCESS;
} 
