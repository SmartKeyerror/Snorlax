

/*
 * Design a class to find the kth largest element in a stream. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Implement KthLargest class:
 * - KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
 * - int add(int val) Returns the element representing the kth largest element in the stream.
 * 
 * 在一个数据流中寻找第 K 个最大元素，add() 方法有两个功能，一个是添加元素，另一个则是将第 K 大的元素返回。
 * 
 * 数据流求 top-K 问题，如果是 top-K 最大元素的话，使用小堆顶; 如果是 tok-K 最小元素的话，使用大堆顶
 * 
 * 以 top-K 最大元素为例，假设 K = 4，并且完全二叉树为:
 * 
 *      5
 *     / \
 *    7   9
 *   /
 *  21
 * 
 * [21, 9, 7, 5]，第 4 大的元素恰好就是堆顶元素 5，那么我们就可以使用 O(1) 的时间复杂度取出。并且，假设新增的元素为 4，小于堆顶元素，
 * 也就是新添加的元素比堆顶最小的元素还要小，那么第 K 大的元素肯定轮不到它。
 * 
 */

#include <queue>
#include <vector>

using namespace std;

class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> pool;
public:
    KthLargest(int k, vector<int>& nums) : K(k) {
        for (auto num : nums) {
            pool.push(num);
            if (pool.size() > k) pool.pop();
        }
    }
    
    int add(int val) {
        pool.push(val);
        if (pool.size() > K) pool.pop();
        return pool.top();
    }
};