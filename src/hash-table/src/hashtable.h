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
    double load_factor;             // 负载因子，默认为0.75(参考JDK实现)
} HashTable;

HashTable *new_hash_table(void);

int hash_table_put(HashTable *hash_table, char *key, void *value);

int hash_table_remove(HashTable *hash_table, char *key);

void *hash_table_get(HashTable *hash_table, char *key);

void list_hash_table_keys(HashTable *hash_table, void **buffer);

void free_hash_table(HashTable *hash_table);

#endif