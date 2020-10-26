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

    char s[3];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_tail(linked_list, s, value);
    }

    TEST_ASSERT_EQUAL(10, linked_list->size);

    // show_int_linked_list(linked_list);

    free_linked_list(linked_list);
}

static void test_insert_linked_list_head(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[3];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_head(linked_list, s, value);
    }

    TEST_ASSERT_EQUAL(10, linked_list->size);

    // show_int_linked_list(linked_list);

    free_linked_list(linked_list);
}

static void test_pop_linked_list_tail(void) {
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
        result = pop_linked_list_tail(linked_list, s);
    }

    TEST_ASSERT_EQUAL(5, linked_list->size);

    // show_int_linked_list(linked_list);

    free_linked_list(linked_list);
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
        result = pop_linked_list_head(linked_list, s);
    }

    TEST_ASSERT_EQUAL(5, linked_list->size);

    // show_int_linked_list(linked_list);

    free_linked_list(linked_list);
}

static void test_find_element(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[3];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_tail(linked_list, s, value);
    }

    int *res;
    res = find_linked_list(linked_list, "12");
    TEST_ASSERT_EQUAL(6, *res);

    res = find_linked_list(linked_list, "20");
    TEST_ASSERT_EQUAL(NULL, res);

    free_linked_list(linked_list);
}

static void test_delete_element(void) {
    LinkedList *linked_list = new_linked_list();

    TEST_ASSERT_NOT_NULL(linked_list);

    char s[3];
    for (int i = 0; i < 10; i++) {
        int *value = (int *)malloc(sizeof(int));
        memcpy(value, &i, sizeof(int));
        sprintf(s, "%d", i * 2);
        insert_linked_list_tail(linked_list, s, value);
    }

    int *res;
    res = delete_linked_list_node(linked_list, "4");
    TEST_ASSERT_EQUAL(2, *res);
    TEST_ASSERT_EQUAL(9, linked_list->size);

    res = delete_linked_list_node(linked_list, "15");
    TEST_ASSERT_EQUAL(NULL, res);
    TEST_ASSERT_EQUAL(9, linked_list->size);

    free_linked_list(linked_list);

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
