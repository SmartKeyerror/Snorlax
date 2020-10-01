#include <stdlib.h>

typedef struct Heap {
    int size;           /* 当前数组已有元素数量 */
    int capacity;       /* 数组容量 */
    int elements[0];    /* 元素数组 */
} Heap;


Heap *new_heap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap) + sizeof(int) * capacity);

    heap->size = 0;
    heap->capacity = capacity;
    
    return heap;
}


extern int add(Heap *heap, int value);

extern int pop(Heap *heap, int *max_value);

extern Heap *heapify(int elements[], int size, int capacity);

extern int is_empty(Heap *heap);

extern int is_full(Heap *heap);
