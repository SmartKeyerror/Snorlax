#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct list_node {
    struct list_node *next;     // 后继节点
    struct list_node *prev;     // 前驱节点
    void *value;                // 链表节点实际存储的值value
    char key[];                 // 链表节点字符串形式的key
} ListNode;

typedef struct linked_list {
    ListNode *dummy_head;       // 哨兵头节点(永远不会被删除)
    ListNode *dummy_tail;       // 哨兵尾节点(永远不会被删除)
    size_t size;                // 当前链表所保存的元素数量
} LinkedList;

LinkedList *new_linked_list(void);

bool is_linked_list_empty(LinkedList *linked_list);

void insert_linked_list_tail(LinkedList *linked_list, char *key, void *value);

void insert_linked_list_head(LinkedList *linked_list, char *key, void *value);

void *pop_linked_list_head(LinkedList *linked_list, char *key);

void *pop_linked_list_tail(LinkedList *linked_list, char *key);

void *find_linked_list(LinkedList *linked_list, char *key);

void *delete_linked_list_node(LinkedList *linked_list, char *key);

#endif
