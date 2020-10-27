#include "vendor/unity.h"
#include "../src/hashtable.h"
#include "../../../utils/string_utils.h"

#include <stdlib.h>
#include <string.h>


void setUp(void) {}

void tearDown(void) {}

void static test_hash_table_put(void) {
    HashTable *hash_table = new_hash_table();

    TEST_ASSERT_NOT_NULL(hash_table);

    hash_table_put(hash_table, "name", "smart");
    hash_table_put(hash_table, "age", "25");

    TEST_ASSERT_EQUAL(2, hash_table->size);

    free_hash_table(hash_table);
}

void static test_hash_table_get(void) {
    HashTable *hash_table = new_hash_table();

    hash_table_put(hash_table, "website", "https://smartkeyerror.com");
    hash_table_put(hash_table, "project", "Snorlax");

    char *website, *project;
    website = hash_table_get(hash_table, "website");
    project = hash_table_get(hash_table, "project");

    TEST_ASSERT_EQUAL(0, strcmp(website, "https://smartkeyerror.com"));
    TEST_ASSERT_EQUAL(0, strcmp(project, "Snorlax"));

    free_hash_table(hash_table);
}

void static test_hash_table_update(void) {
    HashTable *hash_table = new_hash_table();
    
    hash_table_put(hash_table, "project", "Snorlax");
    hash_table_put(hash_table, "project", "snorlax");

    char *project;
    project = hash_table_get(hash_table, "project");

    TEST_ASSERT_EQUAL(0, strcmp(project, "snorlax"));

    free_hash_table(hash_table);
}

void static test_hash_table_remove(void) {
    HashTable *hash_table = new_hash_table();
    
    hash_table_put(hash_table, "profession", "Mechanical Engineering And Automation");
    hash_table_put(hash_table, "profession-2", "Computer Science");

    int res = hash_table_remove(hash_table, "profession");
    TEST_ASSERT_EQUAL(0, res);

    char *profession;
    profession = hash_table_get(hash_table, "profession");
    TEST_ASSERT_EQUAL(NULL, profession);

    TEST_ASSERT_EQUAL(1, hash_table->size);

    free_hash_table(hash_table);
}

void test_expand_hash_table(void) {
    HashTable *hash_table = new_hash_table();

    unsigned int len = 10;
    char random_buffer[len+1];
    for (int i = 0; i < 32; i++) {
        generate_random_string(random_buffer, len);
        hash_table_put(hash_table, random_buffer, "Same Value");
    }
    TEST_ASSERT_EQUAL(64, hash_table->capacity);

    char *result = hash_table_get(hash_table, random_buffer);
    TEST_ASSERT_NOT_NULL(result);

    free_hash_table(hash_table);
}


int main() {
    UnityBegin("test/test_hash_table.c");

    RUN_TEST(test_hash_table_put);
    RUN_TEST(test_hash_table_get);
    RUN_TEST(test_hash_table_update);
    RUN_TEST(test_hash_table_remove);
    RUN_TEST(test_expand_hash_table);
    
    return UnityEnd();
}
