## 堆: 堆排序、TopK、计算百分位数，我的能量超乎你想象

堆是一个非常有意思的数据结构，堆结构脱胎于树结构，具有平常树结构的所有特点。但是，堆又是特殊的：堆只在乎堆顶的那一个元素。

堆结构最为广泛的应用就是优先队列、定时器的实现，以及部分场景下百分位数的计算，TOP-K 的问题同样可以使用堆解决。

### 1. 堆的表示

堆是一棵完全二叉树，可以使用数组进行存储，并使用数组索引来访问节点的左右子节点。并且，堆中的每一个节点值都必须大于等于（或者小于等于）其子树中每个节点的值。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/heap/heap.png)

对于一个节点 `node` 而言，若其在数组内的索引为 `n`，则有如下节点计算公式：

- 左孩子节点索引：2n + 1
- 右孩子节点索引：2n + 2
- 父节点索引：(n - 1) / 2 （向下取整）

```cpp
static size_t get_left(size_t index) {
    return 2 * index + 1;
}

static size_t get_right(size_t index) {
    return 2 * index + 2;
}

static size_t get_parent(size_t index) {
    return (index - 1) / 2;
}
```

虽然堆可以直接使用数组进行表示，但是由于元素的动态添加特性，以及 C 语言的语言特性，不得不使用结构体+柔型数组的方式实现：

```cpp
#include <stdlib.h>
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

bool max_heap_operate(size_t left, size_t right) {
    return (left > right);
}

bool min_heap_operate(size_t left, size_t right) {
    return (left < right);
}

/* 一个简单的工厂函数 */
Heap *new_heap(size_t capacity, int heap_type) {
    Heap *heap = (Heap *)malloc(sizeof(Heap) + sizeof(int) * capacity);

    heap->size = 0;
    heap->capacity = capacity;

    switch (heap_type) {
    case MAX_HEAP:
        heap->operate = max_heap_operate;
        break;
    case MIN_HEAP:
        heap->operate = min_heap_operate;
        break;
    default:
        free(heap);
        return NULL;
    }
    
    return heap;
}
```

`operate` 函数指针以及 `HeapType` 枚举类型用于实现大小堆的创建，C 语言中实现“鸭子类型”比其它语言更为简单，


#### 1.1 元素的插入

向堆中插入元素时，首先将元素添加至数组末尾，然后不断地和父节点进行比较、交换，直到落入到正确的位置（小于等于或大于等于父节点）。由于元素的“运动”路径由下而上，所以又称之为“上浮”操作。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/heap/shift--up.png)

```cpp
static void shift_up(Heap *heap, size_t index) {
    while (index > 0 && heap->operate(heap->elements[index], heap->elements[get_parent(index)])) {
        swap(heap, index, get_parent(index));
        index = get_parent(index);
    }
}

int add(Heap *heap, int value) {
    if (heap->size == heap->capacity)
        return -1;
    
    heap->elements[heap->size] = value;
    shift_up(heap, heap->size);
    
    heap->size++;

    return 0;
}
```

#### 1.2 元素的弹出

堆只有弹出堆顶元素这一个删除操作，因为堆并不像 BST 一样，每一个元素都有其特定的意义。堆只有堆顶的元素才具有特定的意义。

在弹出堆顶元素之后，为了避免数组的移动，将数组最后一个元素置于堆顶，然后不断地和其左、右子节点进行比较、交换，直到落入到正确的位置（小于等于或大于等于孩子节点）。由于元素的“运动”路径由上而下，所以又称之为“下沉”操作。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/heap/shift-down.png)

```cpp
static void shift_down(Heap *heap, size_t index) {
    /* 当元素没有左子节点或者是当前节点大于左右子节点时，下沉结束 */
    while (get_left(index) < heap->size ) {

        /* 暂定左子节点为值最大(或最小)的节点 */
        size_t max = get_left(index);

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

int pop(Heap *heap, int *max_value) {
    if (heap->size == 0) 
        return -1;
    
    *max_value = heap->elements[0];

    /* 将最后一个元素与第一个元素进行交换 */
    swap(heap, 0, heap->size - 1);
    heap->size--;

    shift_down(heap, 0);

    return 0;
}
```

#### 1.3 快速建堆（堆化）

当我们已有一个元素数组需要对其使用堆结构表示时，不需要遍历该数组并逐一调用 `add` 方法，而是使用堆化的方式快速建堆。即**从最后一个非叶子节点开始，对每一个非叶子节点进行“下沉”操作**。而最后一个非叶子节点其实就是最后一个节点的父节点。

```cpp
/* 使用已有数组快速建堆 */
Heap *heapify(int elements[], size_t size, size_t capacity, int heap_type) {
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
```

### 2. 堆的应用

#### 2.1 计算百分位数

百分位数是衡量一组数据一个非常重要的指标，对于 Web Server 的响应时间而言，第 95 个百分位数、第 99 个百分位数能直接反映出服务的整体时延。

百分位数通常使用 `P50`、`P95`、`P99` 等方式表示，其中 `P50` 其实就是中位数。`P99` 表示在当前样本数据中，有 99% 的数据大于等于（或小于等于）该数值，有 1% 的数据大于等于（或小于等于）该数值。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/heap/percentile.png)

对于静态数据而言，只需要将数据排序，而后取出位置在 50%、95%、99% 的数据即可。但是对于动态数据，或者说流式数据而言，使用数组排序的代价稍有昂贵，所以，此时通常都会使用堆的方式实现：对于计算 P50 而言，需要维护两个堆，一个大堆，一个小堆，并保证两个堆中的数据量相差不超过 1（因为是 P50，所数据需要对半分，奇数个数据对半分之后需对其进行取整）。如此一来，对于整体数据量为奇数的中位数来说，我们只需要取多出来一个元素的堆的堆顶元素即可。而对于整体数据量为偶数的中位数来说，则取两个堆的堆顶元素取平均数即可。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/heap/cal-percentile.png)

当新添加的元素大于大堆顶的元素时，该数据应被推入至小堆。当新添加的元素小于小堆顶的元素时，该数据应被推入至大堆。在某一个堆添加元素之后，可能会打破两个堆的平衡，对于 P50 而言，两个堆的比例应为 1: 1，对于 P99 而言，两个堆的比例应为 99: 1。

> https://github.com/SmartKeyerror/Snorlax/blob/master/src/heap/src/percentile.c

### 3. 运行单元测试

```bash
make test
```