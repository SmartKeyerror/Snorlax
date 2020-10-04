#include "heap.h"

#include <stdio.h>
#include <string.h>


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


int is_empty(Heap *heap) {
    return heap->size == 0;
}


int is_full(Heap *heap) {
    return heap->size == heap->capacity;
}


static void shift_up(Heap *heap, int index) {
    while (index > 0 && heap->operate(heap->elements[index], heap->elements[get_parent(index)])) {
        swap(heap, index, get_parent(index));
        index = get_parent(index);
    }
}


/* 向堆中添加元素 */
int add(Heap *heap, int value) {
    if (is_full(heap))
        return -1;
    
    heap->elements[heap->size] = value;
    shift_up(heap, heap->size);
    
    heap->size++;

    return 0;
}


static void shift_down(Heap *heap, int index) {
    /* 当元素没有左子节点或者是当前节点大于左右子节点时，下沉结束 */
    while (get_left(index) < heap->size ) {

        /* 暂定左子节点为值最大(或最小)的节点 */
        int max = get_left(index);

        /* 当存在右子节点并且其值大于(或小于)左子节点时，更新最大值(最小值)索引为右子节点*/
        if (max + 1 < heap->size && heap->operate(heap->elements[max + 1], heap->elements[max]))
            max++;
        
        /* 左右子节点中的最值仍比当前节点值小(大)的话，下沉结束 */
        if (heap->operate(heap->elements[index], heap->elements[max]))
            break;
        
        swap(heap, max, index);

        index = max;
    }   
}


/* 弹出堆顶元素 */
int pop(Heap *heap, int *max_value) {
    if (is_empty(heap)) 
        return -1;
    
    *max_value = heap->elements[0];

    /* 将最后一个元素与第一个元素进行交换 */
    swap(heap, 0, heap->size - 1);
    heap->size--;

    shift_down(heap, 0);

    return 0;
}


/* 使用已有数组快速建堆 */
Heap *heapify(int elements[], int size, int capacity, int heap_type) {
    Heap *heap = new_heap(capacity, heap_type);
    heap->size = size;
    heap->capacity = capacity;
    
    for (int i = 0; i < size; i++) {
        heap->elements[i] = elements[i];
    }

    for (int i = get_parent(size - 1); i >= 0; i--)
        shift_down(heap, i);

    return heap;
}


int main() {
    Heap *heap = new_heap(10, MAX_HEAP);

    add(heap, 10);
    add(heap, 9);
    add(heap, 18);
    add(heap, 22);
    add(heap, 29);
    add(heap, 80);
    add(heap, 108);
    add(heap, 500);
    add(heap, 995);
    add(heap, 2322);


    for (int i = 0; i < heap->size; i++) {
        printf("%d, ", heap->elements[i]);
    }
    printf("\n");
    

    int max, size = heap->size;
    
    for (int i = 0; i < size; i++) {
        pop(heap, &max);
        printf("%d, ", max);
    }
    printf("\n");

    int elements[] = {10, 9, 18, 22, 29, 80, 108, 500, 995, 2322};
    Heap *new_heap = heapify(elements, sizeof(elements)/sizeof(int), sizeof(elements)/sizeof(int) * 2, MAX_HEAP);

    for (int i = 0; i < size; i++) {
        pop(new_heap, &max);
        printf("%d, ", max);
    }
    printf("\n");


    int min;

    int new_elements[] = {10, 9, 18, 22, 29, 80, 108, 500, 995, 2322};
    Heap *min_heap = heapify(new_elements, sizeof(new_elements)/sizeof(int), sizeof(new_elements)/sizeof(int) * 2, MIN_HEAP);

    for (int i = 0; i < size; i++) {
        pop(min_heap, &min);
        printf("%d, ", min);
    }
}
