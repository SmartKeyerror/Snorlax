#include "vendor/unity.h"
#include "../src/linked_list.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void setUp(void) {}

void tearDown(void) {}

static void show_int_linked_list(LinkedList *linked_list) {
    ListNode *current = linked_list->dummy_head->next;

    while (current != NULL) {
        if (current->next == linked_list->dummy_tail) {
            printf("%d \n", *(int *)current->value);
            break;
        }
        printf("%d => ", *(int *)current->value);

        current = current->next;
    }
}

static void test_append_value(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    int *value;
    for (int i = 0; i < 10; i++) {
        value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        append(linked_list, value);
    }

    TEST_ASSERT_EQUAL(10, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_insert_head(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    int *value;
    for (int i = 0; i < 10; i++) {
        value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        insert_head(linked_list, value);
    }

    TEST_ASSERT_EQUAL(10, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_pop_tail(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    int *value;
    for (int i = 0; i < 10; i++) {
        value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        append(linked_list, value);
    }

    int *result;
    for (int i = 0; i < 5; i++) {
        pop_tail(linked_list, &result);
    }

    TEST_ASSERT_EQUAL(5, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_pop_head(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    int *value;
    for (int i = 0; i < 10; i++) {
        value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        append(linked_list, value);
    }

    int *result;
    for (int i = 0; i < 5; i++) {
        pop_head(linked_list, &result);
    }

    TEST_ASSERT_EQUAL(5, linked_list->size);

    show_int_linked_list(linked_list);
}

int main() {
    UnityBegin("test/test_stack.c");

    RUN_TEST(test_append_value);
    RUN_TEST(test_insert_head);
    RUN_TEST(test_pop_tail);
    RUN_TEST(test_pop_head);

    return UnityEnd();
}
