#include "vendor/unity.h"
#include "../src/sort.h"

#include <stddef.h>
#include <stdbool.h>

void setUp(void) {}

void tearDown(void) {}


bool verify_orderliness(elementType list[], size_t length, bool (*compare)(elementType a, elementType b)) {
    for (size_t i = 0; i < length - 1; i++) {
        if (compare(list[i], list[i+1]))
            return false;
    }
    return true;
}

static void test_bubble_sort(void) {
    elementType list[] = {10, 15, 22, 88, 70, 90, 100, 5, 9, 45, 30, 22};
    size_t length = sizeof(list) / sizeof(elementType);

    bubble_sort(list, length, more);
    bool res = verify_orderliness(list, length, more);
    TEST_ASSERT_EQUAL(true, res);

    bubble_sort(list, length, less);
    res = verify_orderliness(list, length, less);
    TEST_ASSERT_EQUAL(true, res);
}

static void test_insertion_sort(void) {
    elementType list[] = {10, 15, 22, 88, 70, 90, 100, 5, 9, 45, 30, 22};
    size_t length = sizeof(list) / sizeof(elementType);

    insertion_sort(list, length, less);
    bool res = verify_orderliness(list, length, less);
    TEST_ASSERT_EQUAL(true, res);

    insertion_sort(list, length, more);
    res = verify_orderliness(list, length, more);
    TEST_ASSERT_EQUAL(true, res);
}


int main() {
    UnityBegin("test/test_sort.c");

    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_insertion_sort);

    return UnityEnd();
}
