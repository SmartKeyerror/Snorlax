#include "heap.h"

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * 计算中位数, 数据样本恒定为10000(大堆与小堆的数量各5000)
 */

#define HEAP_SIZE 5000

typedef struct Median {
    Heap *max_heap;
    Heap *min_heap;
    size_t count; 
} Median;

Median *build_median(void) {
    Median *median = malloc(sizeof(Median));
    median->max_heap = new_heap(HEAP_SIZE, MAX_HEAP);
    median->min_heap = new_heap(HEAP_SIZE, MIN_HEAP);
    median->count = 0;
}

void add_to_median(Median *median, int value) {

    int temp;
    median->count++;
    
    // 当两个堆的元素数量相等时，将 value 添加至大堆中，并将大堆顶弹出添加至小堆中

    if (median->max_heap->size == median->min_heap->size) {
        
        add(median->max_heap, value);
        
        if (pop(median->max_heap, &temp) == -1)
            return;
        
        add(median->min_heap, temp);
    } else {        
        // 当两个堆的元素数量不相等时，将 value 添加至小堆，再将小堆顶弹出添加至大堆中

        add(median->min_heap, value);

        if (pop(median->min_heap, &temp) == -1)
            return;
        
        add(median->max_heap, temp);
    }

    return;
}

double find_median(Median *median) {
    int max_value, min_value;
    max_value = min_value = 0;

    if (median->count % 2 == 0) {
        get_top(median->max_heap, &max_value);
        get_top(median->min_heap, &min_value);
        return (max_value + min_value ) / 2.0;
    } else {
        get_top(median->min_heap, &min_value);
        return min_value;
    }
}

int main() {
    Median *median = build_median();

    for (int i = 1; i < 51; i++)
        add_to_median(median, i);
    
    printf("%f", find_median(median));
}
