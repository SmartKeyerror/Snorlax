#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

typedef struct circular_buffer {
    int head;           /* 头指针，指向下一个读取元素的位置 */
    int tail;           /* 尾指针，指向下一个写入元素的位置 */
    int size;           /* 当前缓冲区已有元素数量 */
    int capacity;       /* 环形缓冲区容量 */
    int elements[0];    /* 动态元素数组 */
} CircularBuffer;


int is_empty(CircularBuffer *circular_buffer);

int is_full(CircularBuffer *circular_buffer);

void clear_circular_buffer(CircularBuffer *circular_buffer);

int pop(CircularBuffer *circular_buffer, int *value);

void write(CircularBuffer *circular_buffer, int value);

void delete_circular_buffer(CircularBuffer *circular_buffer);

CircularBuffer *new_circular_buffer(int capacity);

#endif
