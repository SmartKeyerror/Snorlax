#include "vendor/unity.h"
#include "../src/heap.h"

#include <stdlib.h>
#include <string.h>

#define HEAP_SZIE 1024


void setUp(void) {}


void tearDown(void) {}


static void test_build_heap(void) {
    // 测试堆的初始化
    Heap *heap = new_heap(HEAP_SZIE, MAX_HEAP);
    TEST_ASSERT_NOT_NULL(heap);
}


static void test_heapify(void) {
    // 测试堆化
    int max;
    int elements[] = {10, 9, 18, 22, 29, 80, 108, 500, 995, 2322};
    int sorted_elements[sizeof(elements) / sizeof(int)];

    Heap *heap = heapify(elements, sizeof(elements)/sizeof(int), sizeof(elements)/sizeof(int) * 2, MAX_HEAP);

    while (!is_empty(heap)) {
        pop(heap, &max);
        printf("%d, ", max);
    }
    printf("\n");
}


int main() {
    UnityBegin("test/test_heap.c");

    RUN_TEST(test_build_heap);
    RUN_TEST(test_heapify);

    return UnityEnd();
}