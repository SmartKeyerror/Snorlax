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
            printf("%s-%d \n", current->key, *(int *)current->value);
            break;
        }
        printf("%s-%d => ", current->key, *(int *)current->value);

        current = current->next;
    }
}

static void test_insert_linked_list_tail_value(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[2];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_tail(linked_list, s, value);
    }

    TEST_ASSERT_EQUAL(10, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_insert_linked_list_head(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[2];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_head(linked_list, s, value);
    }

    TEST_ASSERT_EQUAL(10, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_pop_linked_list_tail(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[2];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_tail(linked_list, s, value);
    }

    int *result;
    for (int i = 0; i < 5; i++) {
        pop_linked_list_tail(linked_list, s, &result);
    }

    TEST_ASSERT_EQUAL(5, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_pop_linked_list_head(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[3];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_tail(linked_list, s, value);
    }

    int *result;
    for (int i = 0; i < 5; i++) {
        pop_linked_list_head(linked_list, s, &result);
    }

    TEST_ASSERT_EQUAL(5, linked_list->size);

    show_int_linked_list(linked_list);
}

static void test_find_element(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char key[3], value[3];
    for (int i = 0; i < 10; i++) {
        sprintf(key, "%d", i);
        sprintf(value, "%d", i * 2);
        insert_linked_list_tail(linked_list, key, value);
    }

    int res = find_linked_list(linked_list, "5", value);
    TEST_ASSERT_EQUAL(0, res);

    res = find_linked_list(linked_list, "10", value);
    TEST_ASSERT_EQUAL(-1, res);
}

static void test_delete_element(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char key[3], value[3];
    for (int i = 0; i < 10; i++) {
        sprintf(key, "%d", i);
        sprintf(value, "%d", i * 2);
        insert_linked_list_tail(linked_list, key, value);
    }

    int res = delete_linked_list_node(linked_list, "4", value);
    TEST_ASSERT_EQUAL(0, res);
    TEST_ASSERT_EQUAL(9, linked_list->size);

    res = delete_linked_list_node(linked_list, "15", value);
    TEST_ASSERT_EQUAL(-1, res);
    TEST_ASSERT_EQUAL(9, linked_list->size);

}

int main() {
    UnityBegin("test/test_linked_list.c");

    RUN_TEST(test_insert_linked_list_tail_value);
    RUN_TEST(test_insert_linked_list_head);
    RUN_TEST(test_pop_linked_list_tail);
    RUN_TEST(test_pop_linked_list_head);
    RUN_TEST(test_find_element);
    RUN_TEST(test_delete_element);

    return UnityEnd();
}
