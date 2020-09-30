#include <stdlib.h>

typedef struct Heap {
    int size;
    int elements[0];
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


Heap *new_heap(int size) {
    Heap *heap = (Heap *)malloc(sizeof(Heap) + sizeof(int) * size);

    heap->size = 0;
    
    return heap;
}
