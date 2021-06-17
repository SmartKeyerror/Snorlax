
/*
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * 求数组中第 K 大元素，并且数据规模与特征如下:
 * 
 * - 1 <= k <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * 
 * 数据相对比较分散，所以没有办法使用 bucket 的方式来求 Top-K。因此还是使用大小为 K 的小堆顶完成，
 * 
 * 这道题比 703. Kth Largest Element in a Stream 还要更简单一些
 */

#include <queue>
#include <vector>

using namespace std;


// 平均时间复杂度 O(nlogK)，最坏 O(nlogn)；空间复杂度 O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto num : nums) {
            heap.push(num);
            if (heap.size() > k) heap.pop();
        }
        return heap.top();
    }
};