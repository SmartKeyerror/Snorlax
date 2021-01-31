## 位操作那些事儿

### 1. &（AND）

`&` 表示按位“与”，对应的逻辑操作为 AND，只有当两个位均为 1 时，结果才为 1，否则为 0。我们可以根据这个特性来判断一个数的奇偶性，而不用使用 `x % 2` 实现。

对于一个偶数而言，其二进制表示的最低位一定为 0。而对于奇数而言，其二进制表示的最低位一定为 1。所以，我们只需要执行 `x & 1` 即可得到 `x` 到底是奇数还是偶数了:

```bash
10 & 1, 结果为 0，过程如下:

  0000 1010
& 0000 0001
------------
  0000 0000
```

```bash
5 & 1, 结果为 1，过程如下:

  0000 0101
& 0000 0001
------------
  0000 0001
```

除了这个最简单的应用以外，`&` 还可以取一个数二进制表示的指定位数。例如，数值 91 的低 4 位什么? 91 的二进制表示为 `0101 1011`，通过我们的“肉眼”观察可知其低 4 位为 `1011`，那么如何通过 `&` 操作符实现? 

很简单，如果要求数字 n 的第 x 位的话，我们只需要构造一个第 x 位为 1，其余均为 0 的数字，然后执行一下 AND 操作即可。

```bash
91 的低 4 位是什么?

  0101 1011
& 0000 1111
------------
  0000 1011
```

```bash
91 的第 7 位是 1 吗? 

  0101 1011
& 0100 0000 (mask)
------------
  0100 0000
```

`mask` 这一特殊的技巧能够让我们快速地判断给定数值的某一位，或者是某些位的 bit 是否为 1，或者说，是否为 0。这东西其实就叫 BitMask，位掩码，在 Linux 的 OS API 中使用非常非常频繁。

以 `open()` 系统调用为例，`flags` 参数有十几种选择，例如 `O_RDONLY`、`O_WRONLY`、`O_RDWR `、`O_SYNC` 等等。当我们传入的相关的选择项的时候，API 怎么知道我们有没有对某一个位进行设置了呢? 答案就是按位与，若 `flags & O_RDONLY == O_RDONLY` 的话，就说明调用方设置了 `O_RDONLY`。

Leetcode 中 [191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) 让我们计算一个无符号整型数字二进制编码结果中 `1` 的数量，例如 3 使用二进制表示为 `0000 0011`，有 2 个 `1`，所以输出为 2。

假设给定的 Number 为 `X`，那么 `X & 1` 的结果可以判断 `X` 的最后一位是否为 1。如果为 1，那么 `X & 1` 的结果为 1，否则为 0。因此，可以让 `X` 不断地进行右移 1 位，然后和 1 进行按位与，来得到有多少个 1。

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            if (n & 1) res ++;
            n = n >> 1;
        }
        return res;
    }
};
```

稍微复杂一点儿问题就是 [338. Counting Bits](https://leetcode.com/problems/counting-bits/)，不过是求多个数中每个数二进制编码中 `1` 的个数而已。不过，这道题可以使用 DP 的思路进行求解，也就是利用已经计算过的数据来推导下一个数二进制编码中所包含的 `1` 的数量。题解与解释可参考:

> https://github.com/SmartKeyerror/Snorlax/blob/master/leetcode/dynamic-programming/338-Counting-Bits.cpp

### 2. |（OR）

`|` 表示按位“或”，参与运算的的两个对象只要有一个为 1，那么结果就为 1。也就是说，我们可以通过 `|` 操作符给某一个数值的某一个或者某些位置为 1。

```bash
  0000 1101
| 0011 0010
------------
  0011 1111
```

同样以 `open` 系统调用为例，当我们想要以读写的方式打开文件，并且以追加在文件末尾的方式写入数据时，就可以使用 `O_RDWR | O_APPEND` 来同时设置这两个标志位。

在一些权限系统中，我们可以使用 `|` 来设置权限，使用 `&` 来判断是否具有权限。

```cpp
extern const unsigned short INIT  = 0b000;
extern const unsigned short READ  = 0b001;
extern const unsigned short WRITE = 0b010;


int main() {
    int bili = INIT;

    bili |= READ;                   // 赋予读权限
    bool canRead = bili & READ;     // 判断读权限
    bool canWrite = bili & WRITE;   // 判断写权限

    cout<<"bili can read ? "<<canRead<<endl;
    cout<<"bili can write ? "<<canWrite<<endl;

    bili |= WRITE;                  // 赋予写权限
    canWrite = bili & WRITE;
    cout<<"Then, bili can write ? "<<canWrite<<endl;

    return 0;
}
```

### 3. ^ （XOR）

`^` 表示“异或”，只有在运算的两个对象不相等时结果才为 1，否则为 0。异或操作符可以说是一个非常有趣的操作符了，关于异或操作在计算机其它领域的应用，可以参考知乎这篇回答:

> [如何理解「异或」的含义？](https://www.zhihu.com/question/31116687/answer/964367526)

回答中用"找不同"这个非常经典的小游戏来解释异或的含义，个人觉得非常贴切。那么既然异或是用来找不同的，那么相同的位将会被忽略，也就是结果为 0。因此，在上面举的权限管理 Demo 中，异或常常被作为删除权限所用。

```cpp
int main() {
    /* ...... */
    
    bili ^= READ;                   // 删除读权限
    canRead = bili & READ;
    cout<<"Then, bili can read ? "<<canRead<<endl;

    return 0;
}
```

#### 3.1 XOR 一些重要的性质

1. `K ^ 0 = K`，即任何数异或 `0` 之后其值不发生变化。因为异或运算可以看作是**不进位的加法**，任何数加零肯定还是原来那个数。
2. `K ^ K = 0`，两个相同值的数进行异或的结果为 `0`，因为它们之间没有任何的“不同”。
3. `XOR` 满足交换律和结合律，交换律自然不必多说，结合律上可以大做文章。结合上面两条性质，我们可以得到: `K ^ L ^ K = K ^ K ^ L = 0 ^ L = L`。
这个性质可以应用在 Leetcode 的 [136. Single Number](https://leetcode.com/problems/single-number) 问题上，以此找到那个唯一不重复的数字。

4. `XOR` 支持逆运算，即若 `K ^ L = N`，那么有 `K ^ N = L` 或者 `N ^ L = K`。这是一个非常特殊的性质，加减乘除，按位与/或都不满足这条性质，唯独异或满足。通过这个性质，我们可以解决 Leetcode 上许多的问题，例如 [1720. Decode XORed Array](https://leetcode.com/problems/decode-xored-array/)，[1734. Decode XORed Permutation](https://leetcode.com/problems/decode-xored-permutation/)，这两个问题都是 2021 年年初的周赛题目。

