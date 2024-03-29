#include "hashtable.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SUCCESS 0
#define FAIL -1

#define INIT_CAPACITY 16

/*
 * DJB algorithm from Daniel J. Bernstein
 */
static unsigned int hash_calc(const char *str, unsigned int len) {
   unsigned int hash = 5381;

   for(unsigned int i = 0; i < len; str++, i++) {   
      hash = ((hash << 5) + hash) + (*str);
   }   

   return hash;
}

HashTable *new_hash_table(void) {
    HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));

    if (hash_table == NULL) {
        perror("malloc HashTable failed");
        return NULL;
    }

    HashElement **table = (HashElement **)malloc(INIT_CAPACITY * sizeof(HashElement *));

    if (table == NULL) {
        perror("malloc HashTable's table failed");
        free(hash_table);
        return NULL;
    }

    hash_table->size = 0;
    hash_table->table = table;
    hash_table->load_factor = 0.75;
    hash_table->capacity = INIT_CAPACITY;

    // 将所有指针初始化为NULL
    for (unsigned int i = 0; i < INIT_CAPACITY; i++) {
        hash_table->table[i] = NULL;
    }

    return hash_table;
}

static int expand_hash_table(HashTable *hash_table);

static void rehash(HashTable *hash_table, HashElement **new_table, unsigned int new_capacity);

int hash_table_put(HashTable *hash_table, char *key, void *value) {

    if (key == NULL)
        return FAIL;

    unsigned int index = hash_calc(key, strlen(key)) % hash_table->capacity;

    HashElement *element = hash_table->table[index];

    while (element != NULL) {
        if (strcmp(element->key, key) == 0) {
            // 更新即可
            element->value = value;
            return SUCCESS;
        }
        element = element->next;
    }

    HashElement *new_element = (HashElement *)malloc(sizeof(HashElement) + strlen(key) + sizeof(char));

    if (new_element == NULL) {
        perror("malloc new hash element failed");
        return FAIL;
    } else {
        strcpy(new_element->key, key);
        new_element->value = value;
    }
    
    // 将新元素插入至链表头
    new_element->next = hash_table->table[index];
    hash_table->table[index] = new_element;
    hash_table->size++;

    // 计算哈希表实际负载，若超过0.75则进行扩容(非线程安全)
    if (hash_table->size > hash_table->capacity * hash_table->load_factor) {
        int result = expand_hash_table(hash_table);
        return result;
    }

    return SUCCESS;
}

static int expand_hash_table(HashTable *hash_table) {
    /*
     * 扩容规则: 
     *  当 capacity 小于 1024 时，每次扩容增长 1 倍;
     *  当 capacity 大于 1024 时，每次扩容增长 0.25 倍。
     */
    unsigned int new_capacity;

    if (hash_table->capacity < 1024)
        new_capacity = hash_table->capacity * 2;
    else
        new_capacity = hash_table->capacity * 1.25;
    
    // 申请内存
    HashElement **new_table = (HashElement **)malloc(new_capacity * sizeof(HashElement *));

    if (new_table == NULL)
        return FAIL;
    
    rehash(hash_table, new_table, new_capacity);

    return SUCCESS;
}

static void rehash(HashTable *hash_table, HashElement **new_table, unsigned int new_capacity) {
    for (unsigned int i = 0; i < hash_table->capacity; i++) {
        HashElement *current = hash_table->table[i];

        while (current != NULL) {
            HashElement *element = current;

            // 保留当前元素的下一个元素，避免原哈希表链表出现断裂
            current = current->next;

            unsigned int index = hash_calc(element->key, strlen(element->key)) % new_capacity;
            element->next = new_table[index];
            new_table[index] = element;
        }
    }
    // 释放原有table内存空间
    free(hash_table->table);

    hash_table->table = new_table;
    hash_table->capacity = new_capacity;
}


int hash_table_remove(HashTable *hash_table, char *key) {
    unsigned int index = hash_calc(key, strlen(key)) % hash_table->capacity;

    HashElement *previous = NULL; 
    HashElement *current = hash_table->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous != NULL)
                previous->next = current->next;
            else
                hash_table->table[index] = current->next;

            free(current);
            hash_table->size--;
            return SUCCESS;
        }
        previous = current;
        current = current->next;
    }
    return FAIL;
}

void *hash_table_get(HashTable *hash_table, char *key) {
    unsigned int index = hash_calc(key, strlen(key)) % hash_table->capacity;
    HashElement *current = hash_table->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) 
            return current->value;
        
        current = current->next;
    }
    return NULL;
}

void list_hash_table_keys(HashTable *hash_table, void **buffer) {
    int buffer_index = 0;
    for (unsigned int i = 0; i < hash_table->capacity; i++) {
        HashElement *current = hash_table->table[i];

        while (current != NULL) {
            buffer[buffer_index++] = current->key;
            current = current->next;
        }
    }
}

void free_hash_table(HashTable *hash_table) {
    for (unsigned int i = 0; i < hash_table->capacity; i++) {
        HashElement *current = hash_table->table[i];

        while (current != NULL) {
            HashElement *element = current;
            current = current->next;
            free(element);
        }
    }
    free(hash_table->table);
    free(hash_table);
    hash_table = NULL;
}

