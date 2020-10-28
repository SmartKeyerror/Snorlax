## 哈希表: 感受数组的魅力

### 1. 基本概念

哈希表是一种以空间换时间的线性数据结构，其核心就在于哈稀函数。不过在正式介绍哈希表之前，首先来深入了解下数组这一数据结构。

数组是一种在内存中**连续存储**的线性结构，这也就意味着通过索引的方式获取数组中的元素时间复杂度为 O(1)。这是因为数组中每一个元素所占用内存的大小是一样的，对于 `int array[]` 数组而言，每个数组元素占用 4 字节内存空间，那么当我们访问 `array[5]` 时，只需要知道数组的首地址，而后进行最简单的加减乘除计算即可:

```bash
Address(array[5]) = Address(array[0]) + 4 * 5
```

哈希函数是一种将无限集合映射到有限集合的一种特殊函数，这为实现哈希表提供了非常重要的数学基础。哈希表的实现原理其实非常的简单：使用哈希函数计算 `key` 的哈希值(整数)，将此结果对数组的容量进行取余，那么得到的结果就是该元素在当前数组的下标。而前面提到过，通过数组下标获取元素的时间复杂度为 O(1)，所以哈希表在插入、查询与删除等操作下的时间复杂度也为 O(1)。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/hash-table/Hash.png)

哈希函数的设计决定了哈希表的效率，所以一个优秀的哈希函数计算过程应尽可能地简单、高效，并且使结果尽量地分布均匀。这里选用了 DJB 算法，由 Daniel J. Bernstein 实现：

```cpp
static unsigned int hash_calc(const char *str, unsigned int len) {
   unsigned int hash = 5381;

   for(unsigned int i = 0; i < len; str++, i++) {   
      hash = ((hash << 5) + hash) + (*str);
   }   

   return hash;
}
```

```cpp
typedef struct hash_element {
    struct hash_element *next;      // hash冲突解决
    void *value;                    // 实际存储数据指针
    char key[];                     // string
} HashElement;

typedef struct hash_table {
    unsigned int size;              // hashtable实际存储元素数量
    unsigned int capacity;          // 初始化元素数量
    HashElement **table;            // 指针实现的数组，便于扩容
    double load_factor;             // 负载因子，默认为0.75(参考JDK实现)
} HashTable;
```

### 2. 哈希冲突

前面提到的哈希函数，需要将自然界中的所有值都映射在一小范围的集合内，那么在映射时必然存在不同的值所映射的结果相同，这种现象称之为哈希冲突。哈希冲突越多，那么在处理冲突时必然要花费更多的资源，哈希表的效率也就会越低。所以，为了尽可能的避免哈希冲突的出现，数组本身的容量会超过数组中实际存储的元素数量，这就是**以空间换时间**的根本原因。

#### 2.1 开放寻址法

开放寻址法的核心思想是，如果出现了散列冲突，我们就重新探测一个空闲位置，将其插入。一个比较简单的方式就是线性探测：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/hash-table/conflict.png)

简单来说，就是当一个位置被占用的时候，顺着数组往下找，直到找到一个没有被占用的位置，插入该元素。

在查找元素时，通过计算得到了元素位置以后，若数组当前位置元素并不是目标元素，需要顺着数组继续往下找，直到找到元素，或者是碰到了未存储过元素的位置，那么此时表示当前值并不存在于哈希表中。

在开放地址寻址法实现的哈希冲突中，删除元素时不能直接将数组某位置设置为空，因为元素的查找依赖于值为空(NULL)的位置来作为查找的终止。所以，通常会使用一个特殊的标志位，例如一个布尔值，来表示数组某位置元素是否被删除，如此一来不会影响到元素的查找。

#### 2.2 拉链法

在实际应用中，处理哈希冲突更多的是使用拉链法。拉链法的核心思想是，数组中每个位置都对应着一个链表，当出现哈希冲突时，往链表里面追加一个元素。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/hash-table/hash-link.png)

```cpp
int hash_table_put(HashTable *hash_table, char *key, void *value) {
    unsigned int index = hash_calc(key, strlen(key)) % hash_table->capacity;

    HashElement *element = hash_table->table[index];

    while (element != NULL) {
        if (strcmp(element->key, key) == 0) {
            // 更新即可
            element->value = value;
            return SUCCESS;
        }
        element = element->next;
    }

    HashElement *new_element = (HashElement *)malloc(sizeof(HashElement) + strlen(key) + sizeof(char));

    if (new_element == NULL) {
        perror("malloc new hash element failed");
        return FAIL;
    } else {
        strcpy(new_element->key, key);
        new_element->value = value;
    }
    
    // 将新元素插入至链表头
    new_element->next = hash_table->table[index];
    hash_table->table[index] = new_element;
    hash_table->size++;
    
    return SUCCESS;
}
```

### 3. 扩容

在 `HashTable` 结构中有一个非常重要的成员变量: `load_factor`，负载因子。该参数用于描述哈希表数组容量与哈希表中实际存储元素比值的阈值：

```cpp
实际负载因子 = 实际存储元素数量 / 哈希表数组容量
```

当实际负载因子大于1时说明哈希表中必然存在一部分链表的长度大于1，实际负载因子越大，哈希表的查询效率越低。因此，当实际负载因子超过一定的阈值时，我们必须对原有数组进行扩容，并将原来的元素 rehash 到新的数组中。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/hash-table/rehash.png)

```cpp
static int expand_hash_table(HashTable *hash_table) {
    /*
     * 扩容规则: 
     *  当 capacity 小于 1024 时，每次扩容增长 1 倍;
     *  当 capacity 大于 1024 时，每次扩容增长 0.25 倍。
     */
    unsigned int new_capacity;

    if (hash_table->capacity < 1024)
        new_capacity = hash_table->capacity * 2;
    else
        new_capacity = hash_table->capacity * 1.25;
    
    // 申请内存
    HashElement **new_table = (HashElement **)malloc(new_capacity * sizeof(HashElement *));

    if (new_table == NULL)
        return FAIL;
    
    rehash(hash_table, new_table, new_capacity);

    return SUCCESS;
}

static void rehash(HashTable *hash_table, HashElement **new_table, unsigned int new_capacity) {
    for (unsigned int i = 0; i < hash_table->capacity; i++) {
        HashElement *current = hash_table->table[i];

        while (current != NULL) {
            HashElement *element = current;

            // 保留当前元素的下一个元素，避免原哈希表链表出现断裂
            current = current->next;

            unsigned int index = hash_calc(element->key, strlen(element->key)) % new_capacity;
            element->next = new_table[index];
            new_table[index] = element;
        }
    }
    // 释放原有table内存空间
    free(hash_table->table);

    hash_table->table = new_table;
    hash_table->capacity = new_capacity;
} 
```

除了一次性 rehash 的方式之外，Redis 使用了渐进式 rehash 的方式进行，避免大容量的哈希表在扩容时耗时太久阻塞 I/O 线程。渐进式 rehash 本质上是一个双写的过程，即同时维护扩容前和扩容后的哈希表，元素增删改查均在两张哈希表中同时进行。将扩容的时间复杂度均摊到每一次地访问操作上，能最大程度的减少 rehash 的阻塞时间。

Redis 渐进式 rehash 的详细过程可参考 《Redis 设计与实现》：

> http://redisbook.com/preview/dict/incremental_rehashing.html