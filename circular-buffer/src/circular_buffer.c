#include "circular_buffer.h"

#include <stdlib.h>


int is_empty(CircularBuffer *circular_buffer) {
    return circular_buffer->size == 0;
}


int is_full(CircularBuffer *circular_buffer) {
    return circular_buffer->size >= circular_buffer->capacity;
}


int increment_index(int index, int capacity) {
    return (index + 1) % capacity;
}

CircularBuffer *new_circular_buffer(int capacity) {
    CircularBuffer *circular_buffer = (CircularBuffer *)malloc(sizeof(CircularBuffer) + sizeof(int) * capacity);

    // 初始化
    clear_circular_buffer(circular_buffer);
    circular_buffer->capacity = capacity;

    return circular_buffer;
}


void delete_circular_buffer(CircularBuffer *circular_buffer) {
    free(circular_buffer);
}


void clear_circular_buffer(CircularBuffer *circular_buffer) {
    circular_buffer->head = 0;
    circular_buffer->tail = 0;
    circular_buffer->size = 0;
}


int pop(CircularBuffer *circular_buffer, int *value) {
    if (is_empty(circular_buffer))
        return -1;
    
    *value = circular_buffer->elements[circular_buffer->head];
    
    circular_buffer->head = increment_index(circular_buffer->head, circular_buffer->capacity);
    circular_buffer->size--;

    return 0;
}


void write(CircularBuffer *circular_buffer, int value) {
    
    if (is_full(circular_buffer)) {
        // 当缓冲区已满时，将覆盖原有数据，此时头指针必须向前移动
        circular_buffer->elements[circular_buffer->head] = value;
        circular_buffer->head = increment_index(circular_buffer->head, circular_buffer->capacity);        
    } else {
        // 当缓冲区未满时需要自增 size
        circular_buffer->size++;
    }
    
    // 当缓冲区未满时，只需要将数据写入到尾指针指向的位置，并使尾指针前进即可
    circular_buffer->elements[circular_buffer->tail] = value;
    circular_buffer->tail = increment_index(circular_buffer->tail, circular_buffer->capacity);

    return;
}
