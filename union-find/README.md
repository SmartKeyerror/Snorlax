## 判断连通性的利器——并查集

此前在网上看到一句话：通过六个人你就能够认识任何一个陌生人，听着还挺有意思的，也有人给出了一定的数学证明。全球约有 75 亿人口，每个人都会有自己的社交网络，那么我通过什么样的方法才能够知道我和某个人到底能不能通过社交线取得联系呢？比如我认识 B，B 认识 C，C 又认识 D，如此一来我就可以通过 B、C 来认识 D。

如果给全球 75 亿人口建立一张巨大的社交关系网，我如何能够在最快的时间内找出我和某个人是否能够产生关联？并查集正是解决连通性的利器，这是一个基于数组实现的数据结构，内部设计相当巧妙，可以说是“震惊我三观”的数据结构之一，所以放在头篇。

### 1. Quick-Find

首先以一个最为朴素的实现开始：使用数组索引记录节点的标志，节点可能是社交网络中的某一个人，也可能是网络中的某一台路由器，总之我们用一个整数来标记它（字符串可用哈希取模的方式获取整型标志）。而数组中对应的元素值则使用索引值进行初始化，表示节点属于哪个群组。

在初始化时，数组元素如下图所示排布：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/init.png)

当需要将某两个节点进行连通时，将对应索引元素的值变更为同一个即可。例如节点 3 和 节点 4 连通，则将索引为 3 的元素值更新为 4 即可：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/union-3-4.png)

接着，连通节点 4 和节点 7，本应将索引为 4 的元素值更新为 7，但是此时节点 4 和节点 3 连通，那么就需要找到所有与节点 4 连通的节点，将其元素值更新为 7：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/union-4-7.png)

如此一来，在判断两个节点是否连通时即可通过比较数组元素值是否相等进行判断了，如果相等，则说明它们具有连通性，反之则不具备连通性。其实这就是一种朴素的**分组**思想，数组元素表示着“组编号”，拥有同一个组编号的节点自然而然是连通的。

判断连通性只需要访问数组元素进行比较，所以是 O(1) 的时间复杂度。但是连接两个节点则需要**遍历整个数组**，以找到“同组”的节点，所以时间复杂度为 O(n)，这也是为什么此种实现称之为 Quick-Find 的原因。

在具体的 C 实现中，既可以使用简单的数组实现，也可以将数组置于结构体中，并使用动态数组这一技巧实现：

```cpp
#include <stdlib.h>

typedef struct _UnionFind {
    int size;
    int elements[0];
} UnionFind;

UnionFind *initUnionFind(int size) {
    UnionFind *u = (UnionFind *)malloc(sizeof(UnionFind) + size * sizeof(int));

    u->size = size;

    for (int i = 0; i < size; i++) {
        u->elements[i] = i;
    }

    return u;
}
```

所需要实现的 API 其实就两个：判断两个节点的连通性，以及连接两个节点：

```cpp
int get_node(UnionFind *u, int index) {
    return u->elements[index];
}

int is_connected(UnionFind *u, int src, int dst) {
    return get_node(u, src) == get_node(u, dst);
}

void union_node(UnionFind *u, int src, int dst) {
    int src_value = get_node(u, src);
    int dst_value = get_node(u, dst);

    if (src_value == dst_value) return;

    for (int i = 0; i < u->size; i++) {
        if (u->elements[i] == src_value)
            u->elements[i] = dst_value;
    }
}
```

### 2. Quick-Union

Quick-Find 实现虽然能在 O(1) 的时间内判断节点是否连通，但是连通两个节点却要遍历整个数组，当频繁进行连通操作时，将会产生巨大的时间开销。因此，为了提高 union 操作的效率，有了 Quick-Union 实现。

Quick-Union 的核心思想就是利用数组构建出一颗树，非常类似于二叉堆的实现。Quick-Union 算法不再将数组中的元素值作为“组别”，而是**作为当前节点的父节点**。

什么意思呢？当数组初始化时，数组元素值与数组索引值相等，也就是说，所有节点的父节点都指向自己。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/quick-union-init.png)

当我们连接节点 5 和节点 7 时，将节点 5 的父节点更新为节点 7 ，也就是 `elements[5] = elements[7]`：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/union-5-7.png)

紧接着，我们再连接节点 5 和节点 8，如果我们只是简单地执行 `elements[5] = elements[8]` 的话，结果如下图所示：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/wrong-union.png)

也就是说，节点 5 和节点 7 失去了连接关系，显然这是一个错误的连接操作。**在 Qucik-Union 算法实现中，操作的并不是子节点，而是根节点**。这就好比两国会晤，决定事件走向的是两国的头头，而不是底下的杂鱼。因此，我们可以重新定义下连接操作：**连接 A、B 两个节点，实际上是连接 A、B 节点的根节点。**

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/correct-union.png)


当我们判断节点的连通性时，只需要找到两个节点的根节点进行比较即可知道它们是否连通。如果根节点相同，则连通，反之则不连通。

```cpp
// 当 elements[index] = index 时即达到某个节点的根节点
int get_root(UnionFind *u, int index) {
    while (u->elements[index] != index) {
        index = u->elements[index];
    }
    return u->elements[index];
}

// 判断连通性，只要根节点相同，它们就是连通的
int is_connected(UnionFind *u, int src, int dst) {
    return get_root(u, src) == get_root(u, dst);
}

void union_node(UnionFind *u, int src, int dst) {
    int src_root = get_root(u, src);
    int dst_root = get_root(u, dst);

    if (src_root == dst_root) return ;

    // 连接两个节点，实际操作的是根节点
    u->elements[src_root] = dst_root;
}
```

#### 2.1 优化 Quick-Union：优化树高

在连接 A、B 两个节点时只是简单地将节点 A 的根节点挂在节点 B 的根节点上，忽略了两棵树的实际高度：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/high.png)

如上图所示，两种不同的连通方案将会带来不同的结果，很明显地，方案 1 要更优。所以，在连接节点时，我们还需要对树高进行优化。如果要记录树高，我们额外的申请一个数组来进行记录，并在 `union_node` 函数中进行更新。

这里用 C 描述过于费劲，Java 一把唆了:

```java
public class UF:
    private int[] elements;
    private int[] rank;
    
    UF(int N) {
        elements = new int[N];
        rank = new int[N]
        for(int i = 0; i < N; i++) {
            elements[i] = i;
            // 初始化时每棵树的高度均为1
            rank[i] = 1;  
        }
    }
    
    public void union(int src, int dst) {
        int srcRoot = findRoot(src);
        int dstRoot = findRoot(dst);
        
        if (srcRoot == dstRoot) return;
        
        if (rank[srcRoot] < rank[dstRoot]) 
            data[srcRoot] = dstRoot;
            
        else if (rank[srcRoot] > rank[dstRoot]) 
            data[dstRoot] = srcRoot;
            
        else {  
            // 当两棵树的树高相同时，谁指向谁都一样，树高必定会增加
            data[srcRoot] = dstRoot;
            rank[dstRoot] ++;
    }
}

```





#### 2.2 优化 Quick-Union：路径压缩

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/normal.png)

在某些情况下可能会出现如上图所示的情况，此时如果连接节点 4 或者是节点 5 的话，树结构将会退化成链表结构，达到最差查找效率。所以，必须要对根节点到叶子节点的路径进行压缩。

对于 Quick-Union 算法而言，路径压缩并不是一件非常复杂的事情：在连接 A、B 两个节点时，节点 A 不直接连接节点 B，而是连接节点 B 的根节点：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/union-find/path-optimization.png)

路径压缩的这个操作可以在 `get_root` 函数中进行，在寻找根节点时顺带着把路径压缩掉：

```cpp
int get_root(UnionFind *u, int index) {
    while (u->elements[index] != index) {
    
        // 路径压缩“一格”
        u->elements[index] = u->elements[u->elements[index]];
        
        index = u->elements[index];
    }
    return u->elements[index];
}
```

### 3. 小结

并查集是一个非常有趣的数据结构，尤其是利用数组进行分组，以及利用数组构建树结构，都是非常有趣且巧妙的构思。