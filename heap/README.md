## 最上面的石头才会被记住——堆

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
int get_left(int index) {
    return 2 * index + 1;
}

int get_right(int index) {
    return 2 * index + 2;
}

int get_parent(int index) {
    return (index - 1) / 2;
}
```

虽然堆可以直接使用数组进行表示，但是由于元素的动态添加特性，以及 C 语言的语言特性，不得不使用结构体+柔型数组的方式实现：

```cpp
typedef struct Heap {
    int size;           /* 当前数组已有元素数量 */
    int capacity;       /* 数组容量 */
    int elements[0];    /* 柔性数组 */
} Heap;


Heap *new_heap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap) + sizeof(int) * capacity);

    heap->size = 0;
    heap->capacity = capacity;
    
    return heap;
}

```


#### 1.1 元素的插入

向堆中插入元素时，首先将元素添加至数组末尾，然后不断地和父节点进行比较、交换，直到落入到正确的位置（小于等于或大于等于父节点）。由于元素的“运动”路径由下而上，所以又称之为“上浮”操作。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/heap/shift--up.png)

```cpp
static void shift_up(Heap *heap, int index) {
    while (index > 0 && heap->elements[index] > heap->elements[get_parent(index)]) {
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
static void shift_down(Heap *heap, int index) {
    /* 当元素没有左子节点或者是当前节点大于左右子节点时，下沉结束 */
    while (get_left(index) < heap->size ) {

        /* 暂定左子节点为值最大的节点 */
        int max = get_left(index);

        /* 当存在右子节点并且其值大于左子节点时，更新最大值索引为右子节点*/
        if (max + 1 < heap->size && heap->elements[max] < heap->elements[max + 1])
            max++;
        
        /* 左右子节点中的最大节点值仍比当前节点值小的话，下沉结束 */
        if (heap->elements[max] < heap->elements[index])
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
Heap *heapify(int elements[], int size, int capacity) {
    Heap *heap = new_heap(capacity);
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