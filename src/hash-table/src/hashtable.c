#include "hashtable.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SUCCESS 0
#define FAIL -1
#define INIT_CAPACITY 1024

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
    hash_table->capacity = INIT_CAPACITY;

    // 将所有指针初始化为NULL
    for (unsigned int i = 0; i < INIT_CAPACITY; i++) {
        hash_table->table[i] = NULL;
    }

    return hash_table;
}

int hash_table_put(HashTable *hash_table, char *key, void *value) {
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

    return SUCCESS;
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

