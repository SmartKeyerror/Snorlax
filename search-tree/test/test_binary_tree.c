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

int main() {
    UnityBegin("test/test_stack.c");

    RUN_TEST(test_build_binarty_search);
    RUN_TEST(test_build_node);
    RUN_TEST(test_insert_value);
    RUN_TEST(test_find_key);

    return UnityEnd();
}
