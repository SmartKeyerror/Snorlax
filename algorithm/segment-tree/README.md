
## 线段树

线段树多用于处理静态数据，也就是基本上不会进行新增、删除等操作，例如数据库中的用户订单数据、网站的请求数据等。线段树所做的事情就是对某一个区间进行统计工作，例如对区间进行求和，求平均值等等。

![Alt text](./1620524693013.png)

如上图所示，线段树其实就是一棵二叉树，并且这棵二叉树是自底向上构建的。除了叶子节点的原数据以外，非叶子节点均表示一个一个的区间。以求和为例，根节点 `A[0...7]` 表示 `A[0]` 到 `A[7]` 这 8 个数字之和，而 `A[0...3]` 节点则表示 `A[0]` 到 `A[3]` 这 4 个数字之和。

并且可以看到，线段树孩子节点和父亲节点的关系其实是二分的，也就是说，我们可以通过判断父亲节点区间的 `mid` 值来确定接下来到底是左孩子还是去右孩子。 

当需要进行区间查询时，例如查询 `A[4...5]`，那么首先从根节点开始向下遍历，在判断了查询区间所处的范围后，继续向下查询，直到找到 `A[4...5]` 节点，或者是需要找到多个节点，然后进行拼凑。详细的查询过程将在下方描述。

### 1. 线段树的表示

尽管线段树是一棵树结构，但是由于其良好的“二分”性质，使得我们可以不拘泥于使用左、右孩子指针的方式来表示它，同时也可以使用数组的方式进行保存，一如堆那样。

![Alt text](./1620525797428.png)

但是，线段树本身既不是一棵满二叉树，也不是一棵完全二叉树。因此，当我们使用数组对其进行保存时，实际上会浪费掉一些空间：我们需要把最后一层填满。

对于一棵满二叉树而言，**最后一层的节点数量大致等于前面所有层节点之和**，具体推导过程也比较简单，就是一个等比数列求和公式。因此，假如我们有 `n` 个节点，若 `n` 恰好是 `2^k` 的话，那么我们只要 2n 的空间就可以放下所有节点了。若 `n` 不是 2 的 k 的幂的话，那么我们就需要 4n 的空间，才能放下这些节点。

```cpp
// 决定线段树的行为是求和、求平均数还是最小值、最大值等的 interface
template <typename T>
class Merger {
public:
    virtual T merge(const T& a, const T& b) = 0;
};

template <typename T>
class SegmentTree {
private:
    vector<T> m_data;
    vector<T> m_tree;
    Merger<T> *m_counter;
private:
    // 辅助函数，获取左、右孩子索引
    int leftChild(int index) {return 2 * index + 1;}
    int rightChild(int index) {return 2 * index + 2;}
public:
    SegmentTree(const vector<T>& elements, Merger<T> *counter) 
    : m_counter(counter) {
        // 保存原有数据
        m_data = vector<T>(elements.begin(), elements.end());
        
        int total = elements.size();
        // 若原有数据的大小刚好是 2 的 k 的幂的话，那么我们只需要开辟 2n 的空间
        if ((total & (total - 1)) == 0) {
            m_tree = vector<T>(2 * elements.size());
        } else {
            m_tree = vector<T>(4 * elements.size());
        }
        
        // 构建线段树
        buildSegmentTree(0, 0, total - 1);
    }
};
```

这里使用了一个 `Merger` 的抽象类来提高 `SegmentTree` 的扩展性，我们既可以使用求和的方式来构建线段树，也可以使用求平均或者是最小值等方来构建。

### 2. 线段树的构建

线段树的创建是一个自底向上的过程，如果我们想知道根节点的值的话，那么就需要知道左、右两个孩子节点的值。有了左、右孩子两个节点的值之后，以求和为例，我们只需要对其进行相加即可。所以，这是一个很清晰的递归过程。

```cpp
// 在 m_treeIndex 的位置创建区间范围为 [left, right] 的线段树
void buildSegmentTree(int treeIndex, int left, int right) {
    if (left == right) {
        m_tree[treeIndex] = m_data[left];
        return;
    }

    int mid = left + (right - left) / 2;
    int leftChildIndex = leftChild(treeIndex);
    int rightChildIndex = rightChild(treeIndex);

    // 构建左子树
    buildSegmentTree(leftChildIndex, left, mid);
    // 构建右子树
    buildSegmentTree(rightChildIndex, mid + 1, right);

    // 根节点取左、右子树的结果
    m_tree[treeIndex] = m_merger->merge(m_tree[leftChildIndex], m_tree[rightChildIndex]);
}
```

### 3. 线段树的区间查询

![Alt text](./1620544862593.png)

以查询 `[3, 5]` 为例，也就是查询 `A[3]`、`A[4]`、`A[5]` 这三个数的统计结果。首先从根节点出发，来看这个区间是属于左子树还是还是右子树，还是说左右子树各有一部分。根节点所保存的范围为 `[0, 7]`，其中间值为 3，也就是左子树保存了 `A[0...3]` 的结果，右子树保存了 `A[4...7]` 的结果，查询区间刚好在这两个区间中都有重合，所以我们要把两棵子树同时进行遍历。

对于左子树而言，我们需要遍历到叶子节点，而对于右子树而言，`A[4...5]` 就是线段树中的一个非叶子节点，直接取值即可。这种遍历方式其实非常类似于 B-Tree 的范围查询过程，当我们对 B-Tree 或者是 AVL、RBTree 进行范围查询时，都可能需要同时遍历左、右两棵子树才能得到结果。

```cpp
// 在以 treeIndex 为根节点并且其区间范围为 [left, right] 中查询 [queryLeft, queryRight] 这个区间的值
T query(int treeIndex, int left, int right, int queryLeft, int queryRight) {
    if (left == queryLeft && right == queryRight) {
        return m_tree[treeIndex];
    }

    int mid = left + (right - left) / 2;
    int leftChildIndex = leftChild(treeIndex);
    int rightChildIndex = rightChild(treeIndex);

    // 只到左子树中查询的情况
    if (queryRight < mid + 1) {
        return query(leftChildIndex, left, mid, queryLeft, queryRight);
    }

    // 只到右子树中查询的情况
    else if (queryLeft > mid) {
        return query(rightChildIndex, mid + 1, right, queryLeft, queryRight);
    }

    // 需要到左子树以及右子树中进行查找
    T leftResult = query(leftChildIndex, left, mid, queryLeft, mid);
    T rightResult = query(rightChildIndex, mid + 1, right, mid + 1, queryRight);

    // 合并结果
    return m_merger->merge(leftResult, rightResult);
}
```

### 4. 线段树的更新

更新数据也是一个自底向上的过程，首先更新叶子节点，然后逐层向上的更新父节点。

```cpp
// 在以 treeIndex 为根节点且范围为 [left, right] 区间内将索引 updateIndex 的值更新为 updateValue
void update(int treeIndex, int left, int right, int updateIndex, T updateValue) {
    if (left == right) {
        m_data[updateIndex] = updateValue;
        m_tree[treeIndex] = updateValue;
        return;
    }

    int mid = left + (right - left) / 2;
    int leftChildIndex = leftChild(treeIndex);
    int rightChildIndex = rightChild(treeIndex);

    // 到左子树更新
    if (updateIndex < mid + 1) {
        update(leftChildIndex, left, mid, updateIndex, updateValue);
    } else {
        // 到右子树更新
        update(rightChildIndex, mid + 1, right, updateIndex, updateValue);
    }

    // 更新父亲节点
    m_tree[treeIndex] = m_merger->merge(m_tree[leftChildIndex], m_tree[rightChildIndex]);
}
```

### 5. 小结

Leetcode 中 [307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) 这个问题就可以使用线段树的方式进行实现，只需要对接口的名称进行稍加修改即可。题解可参考:

> [307-Range-Sum-Query-Mutable.cpp](https://github.com/SmartKeyerror/Snorlax/blob/master/leetcode/segment-tree/307-Range-Sum-Query-Mutable.cpp)

关于线段树的完整代码如下:

```cpp
#include <vector>
#include <array>
#include <iostream>

using namespace std;

// 决定线段树的行为是求和、求平均数还是最小值、最大值等的 interface
template <typename T>
class Merger {
public:
    virtual T merge(const T& a, const T& b) = 0;
};

template <typename T>
class Add : public Merger<T> {
public:
    T merge(const T& a, const T& b) override {
        return a + b;
    }
};


template <typename T>
class SegmentTree {
private:
    vector<T> m_data;
    vector<T> m_tree;
    Merger<T> *m_merger;
private:
    // 辅助函数，获取左、右孩子索引
    int leftChild(int index) {return 2 * index + 1;}
    int rightChild(int index) {return 2 * index + 2;}

    // 在 m_treeIndex 的位置创建区间范围为 [left, right] 的线段树
    void buildSegmentTree(int treeIndex, int left, int right) {
        if (left == right) {
            m_tree[treeIndex] = m_data[left];
            return;
        }

        int mid = left + (right - left) / 2;
        int leftChildIndex = leftChild(treeIndex);
        int rightChildIndex = rightChild(treeIndex);

        // 构建左子树
        buildSegmentTree(leftChildIndex, left, mid);
        // 构建右子树
        buildSegmentTree(rightChildIndex, mid + 1, right);

        // 根节点取左、右子树的结果
        m_tree[treeIndex] = m_merger->merge(m_tree[leftChildIndex], m_tree[rightChildIndex]);
    }

    // 在以 treeIndex 为根节点并且其区间范围为 [left, right] 中查询 [queryLeft, queryRight] 这个区间的值
    T query(int treeIndex, int left, int right, int queryLeft, int queryRight) {
        if (left == queryLeft && right == queryRight) {
            return m_tree[treeIndex];
        }

        int mid = left + (right - left) / 2;
        int leftChildIndex = leftChild(treeIndex);
        int rightChildIndex = rightChild(treeIndex);

        // 只到左子树中查询的情况
        if (queryRight < mid + 1) {
            return query(leftChildIndex, left, mid, queryLeft, queryRight);
        }

        // 只到右子树中查询的情况
        else if (queryLeft > mid) {
            return query(rightChildIndex, mid + 1, right, queryLeft, queryRight);
        }

        // 需要到左子树以及右子树中进行查找
        T leftResult = query(leftChildIndex, left, mid, queryLeft, mid);
        T rightResult = query(rightChildIndex, mid + 1, right, mid + 1, queryRight);

        // 合并结果
        return m_merger->merge(leftResult, rightResult);
    }

    void update(int treeIndex, int left, int right, int updateIndex, T updateValue) {
        if (left == right) {
            m_data[updateIndex] = updateValue;
            m_tree[treeIndex] = updateValue;
            return;
        }

        int mid = left + (right - left) / 2;
        int leftChildIndex = leftChild(treeIndex);
        int rightChildIndex = rightChild(treeIndex);

        // 到左子树更新
        if (updateIndex < mid + 1) {
            update(leftChildIndex, left, mid, updateIndex, updateValue);
        } else {
            // 到右子树更新
            update(rightChildIndex, mid + 1, right, updateIndex, updateValue);
        }

        // 更新父亲节点
        m_tree[treeIndex] = m_merger->merge(m_tree[leftChildIndex], m_tree[rightChildIndex]);
    }

public:
    SegmentTree(const vector<T>& elements, Merger<T> *merger)
            : m_merger(merger){
        // 保存原有数据
        m_data = vector<T>(elements.begin(), elements.end());

        int total = elements.size();

        // 若原有数据的大小刚好是 2 的 k 的幂的话，那么我们只需要开辟 2n 的空间
        if ((total & (total - 1)) == 0) {
            m_tree = vector<T>(2 *total, 0);
        } else {
            m_tree = vector<T>(4 * total, 0);
        }

        buildSegmentTree(0, 0, total - 1);
    }

    // 范围查询接口
    T queryRange(int left, int right) {
        return query(0, 0, m_data.size() - 1, left, right);
    }

    // 更新接口
    void updateElement(int index, T value) {
        update(0, 0, m_data.size() - 1, index, value);
    }
};


int main() {
    vector<int> ele = {1, 2, 3, 4, 5, 6, 7};

    Merger<int> *adder = new Add<int>();
    SegmentTree<int> seg = SegmentTree<int>(ele, adder);

    seg.updateElement(0, 2);
    cout << seg.queryRange(0, 5) << endl;
}
```