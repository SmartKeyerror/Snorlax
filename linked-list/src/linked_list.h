#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct node {
    void *value;
    struct node *next;
    struct node *prev;
} Node;

typedef struct linked_list {
    Node *dummy_head;
    Node *dummy_tail;
    size_t size;
} LinkedList;

LinkedList *new_lined_list(void);

void append(LinkedList *linked_list, void *value);

void insert_head(LinkedList *linked_list, void *value);

int pop_head(LinkedList *linked_list, void *result);

int pop_tail(LinkedList *linked_list, void *result);

#endif
