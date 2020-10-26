## 栈: C泛型栈如何实现?

### 1. C 语言泛型

C 语言泛型一直是本项目到目前为止闭而不谈的话题之一，C 语言泛型实现起来并不复杂，但是在实际使用的过程中却要比使用指针更为小心，因为 C 泛型和动态语言之间非常类似，即**没有类型检查**，只有在运行时才能发现问题，这无疑增加了程序的调试成本。所以，这也是为什么 C++ 着重的为 C 增加泛型机制的原因之一。

指针中保存了某一个变量或者常量的内存地址，因此，所有指针变量的大小是固定的。在 64 位平台下，指针大小恒定为 8 字节，这是实现泛型最为重要的基础。因此，`void *` 就可以表示 `char *`、`int *`等所有指针变量：反正存储的是一个地址，在间接引用时进行类型转换就好了。

```cpp
int main() {
    void *s;

    int number = 1024;
    s = &number;
    printf("pointer to int: %d \n", *(int *)s);

    s = "Hello World~";
    printf("pointer to string: %s \n", (char *)s);
}
```

### 2. 栈的实现

栈是一种先进后出的通用数据结构，操作系统中的函数调用均采用栈实现。对于一个通用栈而言，通常只有 `push` 和 `pop` 两个 API，其中 `push` 将栈元素压入栈顶，`pop` 将弹出栈顶元素。所以，在数组的尾部实现入栈和出栈的操作可获得最大效率。

既然是泛型栈的实现，在定义栈元素时就必须要使用 `void *`，当我们使用数组实现栈时，由于 C 语言不允许定义 `void []` 数组，所以必须使用指针的方式定义，也就是 `void *`。

```cpp
typedef struct stack {
    size_t size;
    size_t capacity;
    size_t element_size;
    void *elements;
} Stack;
```

在 `Stack` 结构体中，`void *elements` 表示的是一个指向任何元素的数组，数组中保存的可能是 `int`、`long` 或者是指针。所以，需要 `element_size` 来表示栈结构中保存的元素大小，以此来确定栈的总体大小以及数组中边界的确定。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/stack/generic-stack.png)

当压入元素至栈顶时，实际上是将该元素保存在了数组的最后一个元素中:

```cpp
int push(Stack *stack, void *value) {
    if (is_stack_full(stack))
        return FAIL;

    void *target = (char *)stack->elements + stack->size * stack->element_size;
    memcpy(target, value, stack->element_size);

    stack->size++;

    return SUCCESS;
}
```

之所以使用 `memcpy` 将 `value` 所指向的值拷贝到栈元素中，而不是直接地将栈元素指向传入的 `value`，是因为可避免一些于函数栈中分配的变量因为函数的返回而被其它变量所覆盖。但是，这并不能完全避免上述情况，因为 `void *value` 可以指向 `int`，也可以指向 `int *`。

因此，泛型容器大多需要在堆上分配内存，即使是最简单的 `int`。只有这样才能完全地避免函数栈变量因函数返回而被覆盖，这也算是 C 泛型容器的第二个缺点。

栈弹出元素也只是将数组的最后一个元素返回：

```cpp
int pop(Stack *stack, void *value) {
    if (is_stack_empty(stack))
        return FAIL;

    void *stack_top = (char *)stack->elements + (stack->size - 1)  * stack->element_size;
    memcpy(value, stack_top, stack->element_size);

    stack->size--;

    return SUCCESS;
}
```