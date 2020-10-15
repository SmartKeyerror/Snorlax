#include "vendor/unity.h"
#include "../src/stack.h"

#include <stdlib.h>
#include <string.h>

#define STACK_CAPACITY 1024

void setUp(void) {}

void tearDown(void) {}

static void test_push_stack(void) {
    Stack *stack = new_stack(STACK_CAPACITY);

    TEST_ASSERT_NOT_NULL(stack);

    for (int i = 0; i < STACK_CAPACITY; i++) {
        int result = push(stack, i);
        TEST_ASSERT_EQUAL(0, result);
    }

    TEST_ASSERT_EQUAL(1, is_stack_full(stack));

    delete_stack(stack);
}

static void test_pop_stack(void) {
    Stack *stack = new_stack(STACK_CAPACITY);

    TEST_ASSERT_NOT_NULL(stack);

    for (int i = 0; i < STACK_CAPACITY; i++) {
        int result = push(stack, i);
        TEST_ASSERT_EQUAL(0, result);
    }

    int value;
    for (int i = 0; i < STACK_CAPACITY; i++) {
        pop(stack, &value);
        TEST_ASSERT_EQUAL(i + 1, STACK_CAPACITY - value);
    }

    TEST_ASSERT_EQUAL(1, is_stack_empty(stack));

    delete_stack(stack);
}

int main() {
    UnityBegin("test/test_stack.c");

    RUN_TEST(test_push_stack);
    RUN_TEST(test_pop_stack);

    return UnityEnd();
}
