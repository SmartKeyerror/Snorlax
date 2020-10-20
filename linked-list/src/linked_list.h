#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct list_node {
    void *value;
    struct list_node *next;
    struct list_node *prev;
} ListNode;

typedef struct linked_list {
    ListNode *dummy_head;
    ListNode *dummy_tail;
    size_t size;
} LinkedList;

LinkedList *new_linked_list(void);

bool is_linked_list_empty(LinkedList *linked_list);

void append(LinkedList *linked_list, void *value);

void insert_head(LinkedList *linked_list, void *value);

int pop_head(LinkedList *linked_list, void *result);

int pop_tail(LinkedList *linked_list, void *result);

#endif
