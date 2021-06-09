

## 堆

堆本身算是一个比较复杂的数据结构，实现中的 `shiftUp` 以及 `shiftDown` 这两个函数相较于二叉搜索树的节点插入、节点更新要更复杂一些，但是与堆相关的算法问题和 Array、Tree 相比起来却是更简单的，因为堆的模板其实就只有 2 个: 大堆顶和小堆顶。也就是要么求解 Top-K 问题，要么在动态数据中获取最大/最小的元素，能够使用堆解决的算法问题的特征还是比较明显的。

#### Easy

- [1046. 最后一块石头的重量](https://leetcode.com/problems/last-stone-weight/)
- [703. 数据流中的第 K 大元素](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

#### Medium

- [215. 数组中的第 K 个最大元素](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [347. 前 K 个高频元素](https://leetcode.com/problems/top-k-frequent-elements/)
- [692. 前 K 个高频单词](https://leetcode.com/problems/top-k-frequent-words/)
- [378. 有序矩阵中第 K 小的元素](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
- [1642. 可以到达的最远建筑](https://leetcode.com/problems/furthest-building-you-can-reach/)
- [1792. 最大平均通过率](https://leetcode.com/problems/maximum-average-pass-ratio/)

#### Hard

- [295. 数据流的中位数](https://leetcode.com/problems/find-median-from-data-stream/)
