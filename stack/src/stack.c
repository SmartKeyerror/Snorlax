#include "stack.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SUCCESS 0
#define FAIL -1

Stack *new_stack(size_t capacity, size_t element_size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (stack == NULL) {
        perror("malloc Stack failed");
        return NULL;
    }

    stack->elements = malloc(capacity * element_size);

    if (stack->elements == NULL) {
        perror("malloc Stacki failed");
        free(stack);
        return NULL;
    }

    stack->size = 0;
    stack->capacity = capacity;
    stack->element_size = element_size;

    return stack;
}

void delete_stack(Stack *stack) {
    free(stack->elements);
    free(stack);
}

bool is_stack_empty(Stack *stack) {
    return (stack->size == 0);
}

bool is_stack_full(Stack *stack) {
    return (stack->size >= stack->capacity);
}

int push(Stack *stack, void *value) {
    if (is_stack_full(stack))
        return FAIL;
    
    void *target = (char *)stack->elements + stack->size * stack->element_size;
    memcpy(target, value, stack->element_size);

    stack->size++;

    return SUCCESS;
}

int pop(Stack *stack, void *value) {
    if (is_stack_empty(stack))
        return FAIL;
    
    void *stack_top = (char *)stack->elements + (stack->size - 1)  * stack->element_size;
    memcpy(value, stack_top, stack->element_size);

    stack->size--;

    return SUCCESS;
}
