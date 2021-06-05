# Snorlax  

![](https://travis-ci.com/SmartKeyerror/Snorlax.svg?branch=master)

![](./Snorlax.png)

----------

## :telescope:	Algorithm

- [理解二叉树的遍历](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/tree)
- [从栈的“消除”到单调栈](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/stack)
- [回溯与剪枝: 《明日边缘》or 《源代码》](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/backtracking)
- [Flood fill 算法小专题](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/flood-fill)
- [排序: 经典排序算法的思想随处可见](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/sort)
- [与 Top-K 相关的问题](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/top-k)
- [Trie 的原理、实现及其应用](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/trie)
- [线段树的构建、查询与更新](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/segment-tree)

## :fire: 动态规划
- [动态规划(01)——从斐波那契到硬币找零](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/dp/dp(01))
- [动态规划(02)——0-1背包问题](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/dp/dp(02))
- [Coin Change: 自顶向下思考，自底向上实现](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/dp/dp(03))

## :paw_prints: Graph
- [图的二三事—基本概念与基础问题](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/graph/base)
- [BFS与图论问题建模](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/bfs)
- [汉密尔顿回路与欧拉回路](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/graph/loop)
- [最短路径问题——Dijkstra 算法](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/graph/shortest-path/dijkstra)


## :blowfish: Other Algorithm Topics

- [N-Sum 问题](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/N-Sum)
- [位操作那些事儿](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/bit-manipulation)
- [Leetcode 中的排列问题](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/permutation)
- [Prefix Sum 与 Prefix XOR](https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/prefix-sum)


## :ghost: System Design

- [如何设计一个 TinyURL 系统？](https://github.com/SmartKeyerror/Snorlax/tree/master/system-design/tiny-url)

------

## Algorithm Summary

### Binary Tree

| 方法     | 注意点                   | 能够解决的问题 |
| :------: | :-----------------------: | :------------ |
| 前序遍历 | **将根节点的信息传递至左右子树** | 验证 BST: [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)<br>判断两棵树是否完全相同: [100. Same Tree](https://leetcode.com/problems/same-tree/)<br>判断是否为子树: [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)<br>根节点到叶子节点的路径问题: [113. Path Sum II](https://leetcode.com/problems/path-sum-ii/) <br>**所有二叉树的构造问题都是前序遍历**: [108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
| 中序遍历 | **BST 的中序遍历结果有序** | 验证 BST: [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)<br> BST 中第 K 小/大的元素: [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) |
| 后序遍历 | **将左右子树的信息传回给根节点** | 二叉树的最大高度: [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) <br> 二叉树的最小高度: [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) <br> 翻转二叉树: [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) <br> 翻转二叉树为链表: [114. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) <br> **最近公共祖先问题:** [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) <br> DP + BinaryTree: [337. House Robber III](https://leetcode.com/problems/house-robber-iii/) |
| 层序遍历 | 使用 `queue` 保存每一层的节点 <br> **BFS 用于求解无权图最短路径** | 寻找二叉树每一行的最大节点值: [515. Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) <br> 二叉树的右视图: [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) <br> 多叉树最短路径问题: [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) <br> **二叉树中所有距离为 K 的节点**: [863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)


------
## :beers: Interesting Problems

### Danamic Programing

- [Coin Change 及其变种问题](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/leetcode/dp/Coin-Change.pdf)

### Linked-List

- [单链表 A、B 可能有环，也可能无环。这两个链表可能相交，也可能不相交，若相交请返回相交节点，否则返回 null。额外空间复杂度请达到 O(1)](#intersection-of-two-linked-list)

<!-- ## :toolbox: Data Structure

- [并查集: 没人比我更懂连通性](https://github.com/SmartKeyerror/Snorlax/tree/master/src/union-find)
- [递归: 面试叫我小甜甜，生产叫我小垃圾?](https://github.com/SmartKeyerror/Snorlax/tree/master/src/recursive)
- [堆: 堆排序、TopK、计算百分位数，我的能量超乎你想象](https://github.com/SmartKeyerror/Snorlax/tree/master/src/heap)
- [环形队列: 我吃我自己](https://github.com/SmartKeyerror/Snorlax/tree/master/src/circular-buffer)
- [二分搜索树: 简简单单，描述二叉树所有的性质](https://github.com/SmartKeyerror/Snorlax/tree/master/src/search-tree)
- [栈: C泛型栈如何实现?](https://github.com/SmartKeyerror/Snorlax/tree/master/src/stack)
- [哈希表: 感受数组的魅力](https://github.com/SmartKeyerror/Snorlax/tree/master/src/hash-table) -->


#### intersection-of-two-linked-list

![](interesting-problems/intersection-of-two-linked-list.png)
