
## 递归——俄罗斯套娃

递归是程序设计中一个非常重要的思想，尽管因为栈帧数量的限制，在实际的生产环境中较少使用，但是这并不能降低递归思想对程序设计的影响。更何况可以使用尾递归来优化栈帧的数量。

### 1. 递归的核心思想：将问题拆解成同样的、更小的问题

递归的核心思想其实就是将一个大问题拆解成同样的、更小的问题，直到问题无法拆解或者我们已经得知了更小问题的解。

以阶乘为例，对于 $ n! $ 我们可以很轻松的写出 $n! = n * (n-1)!$，而 $ (n-1)!$ 又可以写作为 $ (n-1) * (n-2)! $。所以，阶乘问题的**通用解**即为：

$$ f(n) = n * f(n-1) \ \ \ \ \ \ \ \ \ \ \ \ \ (n >= 1)$$

最小问题即为 $1! = 1$。在明确了通用解和最小问题之后，我们就可以写出阶乘的递归函数了：

```cpp
int factorial(int n) {

    // 最小问题解
    if (n == 1)
        return 1;
    
    // 通用解
    return n * factorial(n-1);
}
```

所以，理解递归的核心关键点有两个：递归终止条件，找到问题的通用解。前者通常都比较容易，后者在一些较为抽象的问题上并不容易找到。不过，熟能生巧，多看一些关于递归的用例，找到感觉，其它复杂问题自然能迎刃而解。

### 2. 递归的函数调用过程

递归是调用自身的一种函数，说到底还是一个函数，仍然由栈和栈帧实现。以 `factorial(4)` 为例，用图例来更加直观的描述递归调用的过程。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/recursive/factorial.png)

递归函数在调用过程中一个非常重要的细节就是在未递归到底时，所有函数的栈帧均会保留在栈中。当最底层的函数开始返回时，上一个函数调用能够接收该函数返回的结果，**如何接收上一个函数返回的结果，将是编写递归函数最为重要的关键点之一**。在阶乘的递归实现中，使用乘法进行接收，同样地也可以使用加法进行接收，此时将计算 `1...n` 的等差数列和。

正因为递归调用在未达到递归终止条件时将一直保持并创建栈帧，所以递归函数将会带来比较大的内存开销，这也是为什么递归函数在实际生产中使用不多的原因。

### 3. 递归用例

#### 3.1 青蛙跳台阶问题

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

问题的最小解在题目中已经告知了：当只有一个台阶时，青蛙只能有一种跳法，所以结果为 1 种。当有两个台阶时，青蛙可以直接跳两级，也可以一次跳一级，跳两次，所以为 2 种。

再来看如何获得通用解，当有 n 个台阶时，要么青蛙从 n-1 级台阶上直接跳上来，要么从 n-2 级台阶上跳上来。如此一来，问题就简单了，把这两种跳法加起来不就是最终结果了吗。

$$ f(n) = f(n-1) + f(n-2) $$

```cpp
int jump(int n) {

    // 最小问题解
    if (n <= 2)
        return n;

    // 通用解
    return jump(n-1) + jump(n-2);
}
```

#### 3.2 链表反转问题

反转一个链表算是比较经典的抽象递归问题，现在来看下问题：

> 给定一个单向链表，原地反转该链表，如原链表为 1 —> 2 -> 3，反转后链表为 3 -> 2 -> 1。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/recursive/LinkedList.png)

如上图所示，一个链表完全可以看作是**一个头节点链接着下一个更大的链表**，链表的这一特性其实就是问题的通用解。所以，我们只需要将眼光放在如何反转这个链表上即可。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/recursive/Reverse-LinkedList.png)

```cpp
Node node = head.next;
node.next = head;
head.next = NULL;
```

只需要三行代码即可完成通用解的实现。完整代码如下：

```cpp
typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *reverse(Node *head) {

    if (head == NULL || head->next == NULL)
        // 当递归到链表最后一个节点时，该节点其实就是新的链表头
        return head;
    
    // 递归到底后将返回新的链表头
    Node *newHead = reverse(head->next);

    Node *node = head->next;
    node->next = head;
    head->next = NULL;

    return newHead;
}
```

实际上，递归可以看作是一个开销巨大的遍历。在链表这个场景下，当函数持续调用时，为从头到尾遍历。当函数开始返回时，为从尾到头遍历。正是因为函数调用的特性，才使得递归拥有强大的威力。

#### 3.3 求二叉树最大深度问题

> 给定一棵二叉树，求其最大深度。

二叉树是一种树结构，每一个节点都可能拥有一个左子节点和一个右子节点：

```cpp
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
```

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/recursive/bt.png)

如上图所示，二叉树其实也是一种天然的递归结构，可以看做是一个根节点加两棵子树所组成的递归结构。回到正题，首先确定递归的终止条件，很明显的，当某一个节点既没有左子节点又没有右子节点时递归将终止。再来看通用解，其实就是左子树和右子树高度的最大值。

```cpp
int maxDepth(TreeNode *root) {
    if (root == NULL)
        return 0;
    
    // 取左子树最大深度
    int leftDepth = maxDepth(root->left);

    // 取右子树最大深度
    int rightDepth = maxDepth(root->right);

    // 由于递归终止条件递归到了 NULL 节点，所以最大高度需要加 1
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
```

在编写递归函数时，千万不要陷入到递归函数的具体调用过程中。我们只需要牢记当前函数的具体功能语义，再结合递归终止条件和一般通用解即可得出正确的答案。**递归是一种宏观的、自上而下的思考方式**。

#### 3.4 使用递归计算 $x^n$

$x^n$ 其实就是 $n$ 个 $x$ 相乘，根据指数运算公式可得(分治思想)：

$$ x^n = (x^{\frac{n}{2}})^2 $$

由此，我们就得出了问题的通用解：

$$ f(n) = (f({\frac{n}{2}}))^2 $$

但是对于程序而言，我们更愿意去计算整数幂，而不是小数幂，所以需要对 $n$ 的奇偶性进行区分。

$$ f(n)=\left\{
\begin{aligned}
& (x^{n / 2})^2 \ \ (n为偶数) \\
& x * (x^{n / 2})^2  \ \ (n为奇数)\\
\end{aligned}
\right.
$$

```cpp
#include <math.h>

double exponentiation(double x, int n);

double my_pow(double x, int n) {
    // 当 n 为负数时，对结果取倒数即可
    if (n < 0)
        return 1 / exponentiation(x, n);
    return exponentiation(x, n);
}

double exponentiation(double x, int n) {
    
    if (n == 0)
        return 1;
    
    if (n == 1) 
        return x;
    
    double res = exponentiation(x, floor(n  / 2));

    if (n % 2 == 0) {
        return res * res;
    } else {
        return res * res * x;
    }
}
```