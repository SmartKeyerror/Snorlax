
## 将数组当成一个环——环形缓冲区

环形缓冲区（Circlar Buffer）是一种非常常见、并且对内存空间利用率较高的一种数据结构，MySQL 中的 redo log 尽管实际存在于硬盘中，依然可以作为环形缓冲区看待。在 MapReduce 模型中，Map 端的 Shuffle 阶段产生的临时文件，同样保存在环形缓冲区中。

当必须对某一个缓冲区进行内存大小限制，并且允许进行覆写时，使用环形缓冲区为最佳选择。

### 1. 基本概念与实现

假设使用数组实现环形缓冲区，在初始化时只需要初始化一定数量的空数组即可，并定义头、尾指针，其中头指针指向缓冲区的队首元素，而尾指针则表示下一个写入数据的位置。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/circular-buffer/init.png)

```cpp
typedef struct circular_buffer {
    int head;           /* 头指针，指向下一个读取元素的位置 */
    int tail;           /* 尾指针，指向下一个写入元素的位置 */
    int size;           /* 当前缓冲区已有元素数量 */
    int capacity;       /* 环形缓冲区容量 */
    int elements[0];    /* 动态元素数组 */
} CircularBuffer;


CircularBuffer *new_circular_buffer(int capacity) {
    CircularBuffer *circular_buffer = (CircularBuffer *)malloc(
        sizeof(CircularBuffer) + sizeof(int) * capacity
    );

    // 初始化
    clear_circular_buffer(circular_buffer);
    circular_buffer->capacity = capacity;

    return circular_buffer;
}


void clear_circular_buffer(CircularBuffer *circular_buffer) {
    circular_buffer->head = 0;
    circular_buffer->tail = 0;
    circular_buffer->size = 0;
}
```

当写入元素时，尾指针向前移动，头指针在未弹出元素时保持不变。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/circular-buffer/add-item.png)

当从缓冲区中弹出元素时，从头指针指向的数据开始弹出。所以，环形缓冲区本质上就是一个 FIFO（先进先出）队列。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/circular-buffer/pop-item.png)

```cpp
int increment_index(int index, int capacity) {
    return (index + 1) % capacity;
}


int pop(CircularBuffer *circular_buffer, int *value) {
    if (is_empty(circular_buffer))
        return -1;
    
    *value = circular_buffer->elements[circular_buffer->head];
    
    circular_buffer->head = increment_index(circular_buffer->head, circular_buffer->capacity);
    circular_buffer->size--;

    return 0;
}

```

当尾指针指向数组的最后一个元素时，继续向缓冲区写入数据时，尾指针将会再次指向数组的第一个元素，这也是环形缓冲区的由来：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/circular-buffer/rehead.png)

由于缓冲区的容量固定，当数据写入速度大于元素弹出速度时，迟早会被写满，当缓冲区已满时，头、尾指针将再次指向同一个位置：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/circular-buffer/full.png)

此时再写入数据时，可以直接返回错误，或者是覆盖头指针所指向的元素。若是覆盖写入，在没有元素弹出时，头尾指针将永远地指向同一个元素，并共同向前移动。

```cpp
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
```

### 2. 运行单元测试

```bash
make test
```