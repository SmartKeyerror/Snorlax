#include "vendor/unity.h"
#include "../src/binary_search_tree.h"

#include <stdlib.h>
#include <string.h>

void setUp(void) {}

void tearDown(void) {}

void test_build_binarty_search(void) {
    BinaryTree *binary_tree = new_binary_tree();
    TEST_ASSERT_NOT_NULL(binary_tree);
    
    delete_binary_tree(binary_tree);
}

void test_build_node(void) {
    int key = 15;
    char *s = "Hello Binary Tree~";

    Node *node = new_node(key, &s);

    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_NOT_NULL(node->value);

    // node->value 此时是一个 void * 指针，需要转换成指向字符串的指针，即 char **
    int res = strcmp(s, *(char **)node->value);
    TEST_ASSERT_EQUAL(0, res);
}

 void test_insert_value(void) {
    BinaryTree *binary_tree = new_binary_tree();
    TEST_ASSERT_NOT_NULL(binary_tree);

    char *h = "hello";
    char *b = "binary";
    char *t = "tree";

    insert(binary_tree, 10, &h);
    insert(binary_tree, 8, &b);
    insert(binary_tree, 15, &t);
    insert(binary_tree, 15, NULL);
    TEST_ASSERT_EQUAL(3, binary_tree->count);

    delete_binary_tree(binary_tree);
 }

 void test_find_key(void) {
    BinaryTree *binary_tree = new_binary_tree();
    TEST_ASSERT_NOT_NULL(binary_tree);

    char *h = "hello";
    char *b = "binary";
    char *t = "tree";

    insert(binary_tree, 10, &h);
    insert(binary_tree, 8, &b);
    insert(binary_tree, 15, &t);
    insert(binary_tree, 22, NULL);
    insert(binary_tree, 80, NULL);

    Node result;
    int res = find(binary_tree, 15, &result);

    TEST_ASSERT_EQUAL(0, res);
    TEST_ASSERT_EQUAL(15, result.key);

    res = strcmp("tree", *(char **)result.value);
    TEST_ASSERT_EQUAL(0, res);
}

int test_delete_node(void) {
    BinaryTree *binary_tree = new_binary_tree();
    TEST_ASSERT_NOT_NULL(binary_tree);

    char *h = "hello";
    char *b = "binary";
    char *t = "tree";
    char *s = "string";

    insert(binary_tree, 10, &h);
    insert(binary_tree, 8, &b);
    insert(binary_tree, 15, &t);
    insert(binary_tree, 22, &s);
    insert(binary_tree, 80, NULL);

    delete(binary_tree, 8);

    TEST_ASSERT_EQUAL(4, binary_tree->count);
}

void test_midorder(void) {
    BinaryTree *binary_tree = new_binary_tree();
    TEST_ASSERT_NOT_NULL(binary_tree);

    insert(binary_tree, 99, NULL);
    insert(binary_tree, 87, NULL);
    insert(binary_tree, 25, NULL);
    insert(binary_tree, 105, NULL);
    insert(binary_tree, 188, NULL);
    insert(binary_tree, 104, NULL);
    insert(binary_tree, 106, NULL);
    insert(binary_tree, 200, NULL);
    insert(binary_tree, 10, NULL);
    insert(binary_tree, 9, NULL);
    insert(binary_tree, 54, NULL);
    insert(binary_tree, 32, NULL);
    insert(binary_tree, 66, NULL);

    midorder(binary_tree);
}

void test_level_order(void) {
    BinaryTree *binary_tree = new_binary_tree();
    TEST_ASSERT_NOT_NULL(binary_tree);

    insert(binary_tree, 99, NULL);
    insert(binary_tree, 87, NULL);
    insert(binary_tree, 25, NULL);
    insert(binary_tree, 105, NULL);
    insert(binary_tree, 188, NULL);
    insert(binary_tree, 104, NULL);
    insert(binary_tree, 106, NULL);
    insert(binary_tree, 200, NULL);
    insert(binary_tree, 10, NULL);
    insert(binary_tree, 9, NULL);
    insert(binary_tree, 54, NULL);
    insert(binary_tree, 32, NULL);
    insert(binary_tree, 66, NULL);

    levelorder(binary_tree);
}

int main() {
    UnityBegin("test/test_stack.c");

    RUN_TEST(test_build_binarty_search);
    RUN_TEST(test_build_node);
    RUN_TEST(test_insert_value);
    RUN_TEST(test_find_key);
    RUN_TEST(test_delete_node);
    RUN_TEST(test_midorder);
    RUN_TEST(test_level_order);

    return UnityEnd();
}
