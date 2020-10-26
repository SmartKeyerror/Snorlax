#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

typedef struct hash_element {
    struct hash_element *next;      // hash冲突解决
    void *value;                    // 实际存储数据指针
    char key[];                     // string
} HashElement;

typedef struct hash_table {
    unsigned int size;              // hashtable实际存储元素数量
    unsigned int capacity;          // 初始化元素数量
    HashElement **table;            // 指针实现的数组，便于扩容
} HashTable;



#endif