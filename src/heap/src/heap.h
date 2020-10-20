#ifndef __HEAP_H__
#define __HEAP_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct Heap {
    size_t size;                                      /* 当前数组已有元素数量 */
    size_t capacity;                                  /* 数组容量 */
    bool (* operate)(size_t left, size_t right);      /* 操作符函数指针，用于构建不同类型的堆(大堆 or 小堆) */
    int elements[0];                                  /* 元素数组 */
} Heap;

enum HeapType {
    MAX_HEAP = 1,
    MIN_HEAP = 2
};

bool max_heap_operate(size_t left, size_t right);

bool min_heap_operate(size_t left, size_t right);

Heap *new_heap(size_t capacity, int heap_type);

int add(Heap *heap, int value);

int pop(Heap *heap, int *max_value);

Heap *heapify(int elements[], size_t size, size_t capacity, int heap_type);

bool is_empty(Heap *heap);

bool is_full(Heap *heap);

int get_top(Heap *heap, int *top);

void delete_heap(Heap *heap);

#endif
