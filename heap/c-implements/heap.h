#include <stdlib.h>

typedef struct Heap {
    int size;           /* 当前数组已有元素数量 */
    int capacity;       /* 数组容量 */
    int elements[0];    /* 元素数组 */
} Heap;


int get_left(int index) {
    return 2 * index + 1;
}

int get_right(int index) {
    return 2 * index + 2;
}

int get_parent(int index) {
    return (index - 1) / 2;
}

void swap(Heap *heap, int src, int dst) {
    int temp = heap->elements[src];
    heap->elements[src] = heap->elements[dst];
    heap->elements[dst] = temp;
}


Heap *new_heap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap) + sizeof(int) * capacity);

    heap->size = 0;
    heap->capacity = capacity;
    
    return heap;
}
