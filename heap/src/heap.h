#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>


typedef struct Heap {
    int size;                               /* 当前数组已有元素数量 */
    int capacity;                           /* 数组容量 */
    int (* operate)(int left, int right);   /* 操作符函数指针，用于构建不同类型的堆(大堆 or 小堆) */
    int elements[0];                        /* 元素数组 */
} Heap;


enum HeapType {
    MAX_HEAP = 1,
    MIN_HEAP = 2
};


extern int max_heap_operate(int left, int right);

extern int min_heap_operate(int left, int right);

extern Heap *new_heap(int capacity, int heap_type);

extern int add(Heap *heap, int value);

extern int pop(Heap *heap, int *max_value);

extern Heap *heapify(int elements[], int size, int capacity, int heap_type);

extern int is_empty(Heap *heap);

extern int is_full(Heap *heap);

extern int get_top(Heap *Heap, int *top);

#endif
