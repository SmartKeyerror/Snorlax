#include "linked_list.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SUCCESS 0
#define FAIL -1

ListNode *new_list_node(char *key, void *value, ListNode *prev, ListNode *next) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode) + strlen(key) + 1);    // 预留 NUL 的位置

    if (node == NULL) {
        perror("malloc linked list node failed");
        return NULL;
    }

    strcpy(node->key, key);
    node->value = value;
    node->next = next;
    node->prev = prev;

    return node;
}

LinkedList *new_linked_list(void) {
    ListNode *dummy_head = new_list_node("", NULL, NULL, NULL);
    ListNode *dummy_tail = new_list_node("", NULL, NULL, NULL);

    if (dummy_head == NULL || dummy_tail == NULL) return NULL;

    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;

    LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));

    if (linked_list == NULL) {
        perror("malloc linked list failed");
        free(dummy_head);
        free(dummy_tail);
        return NULL;
    }

    linked_list->dummy_head = dummy_head;
    linked_list->dummy_tail = dummy_tail;
    linked_list->size = 0;
}

bool is_linked_list_empty(LinkedList *linked_list) {
    return (linked_list->size == 0);
}

/*
 * 向链表尾部添加元素
 */
void insert_linked_list_tail(LinkedList *linked_list, char *key, void *value) {
    ListNode *tail_node = new_list_node(key, value, linked_list->dummy_tail->prev, linked_list->dummy_tail);

    linked_list->dummy_tail->prev->next = tail_node;
    linked_list->dummy_tail->prev = tail_node;

    linked_list->size++;
}

/*
 * 向链表头部添加元素
 */
void insert_linked_list_head(LinkedList *linked_list, char *key, void *value) {

    ListNode *head_node = new_list_node(key, value, linked_list->dummy_head, linked_list->dummy_head->next);

    linked_list->dummy_head->next->prev = head_node;
    linked_list->dummy_head->next = head_node;

    linked_list->size++;
}

/*
 * 删除链表头元素并返回
 */
int pop_linked_list_head(LinkedList *linked_list, char *key, void *result) {

    if (is_linked_list_empty(linked_list)) return FAIL;

    ListNode *head_node = linked_list->dummy_head->next;

    memcpy(result, head_node->value, sizeof(head_node->value));
    strcpy(key, head_node->key);

    linked_list->dummy_head->next = head_node->next;
    head_node->next->prev = linked_list->dummy_head;

    free(head_node);
    linked_list->size--;

    return SUCCESS;
}

/*
 * 删除链表尾元素并返回
 */
int pop_linked_list_tail(LinkedList *linked_list, char *key, void *result) {

    if (is_linked_list_empty(linked_list)) return FAIL;

    ListNode *tail_node = linked_list->dummy_tail->prev;

    memcpy(result, tail_node->value, sizeof(tail_node->value));
    strcpy(key, tail_node->key);

    linked_list->dummy_tail->prev = tail_node->prev;
    tail_node->prev->next = linked_list->dummy_tail;

    free(tail_node);
    linked_list->size--;

    return SUCCESS;
}

/*
 * 查找key为某一个值的元素
 */
int find_linked_list(LinkedList *linked_list, char *key, void *result) {
    if (is_linked_list_empty(linked_list)) return FAIL;

    ListNode *current = linked_list->dummy_head->next;

    while (current != linked_list->dummy_tail) {
        if (strcmp(current->key, key) == 0) {
            memcpy(result, current->value, sizeof(current->value));
            return SUCCESS;
        }
        current = current->next;
    }
    return FAIL;
}

/*
 * 删除key为某一个值的元素
 */
int delete_linked_list_node(LinkedList *linked_list, char *key, void *result) {
    if (is_linked_list_empty(linked_list)) return FAIL;

    ListNode *current = linked_list->dummy_head->next;

    while (current != linked_list->dummy_tail) {
        if (strcmp(current->key, key) == 0) {
            
            current->prev->next = current->next;
            current->next->prev = current->prev;
            memcpy(result, current->value, sizeof(current->value));
            
            free(current);
            linked_list->size--;

            return SUCCESS;
        }
        current = current->next;
    }
    return FAIL;
}
