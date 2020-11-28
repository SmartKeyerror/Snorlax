
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:

    // 最简单、最直观的方式就是用一个大堆将所有元素压入，而后弹出第 k 个元素
    // Runtime: 40 ms, faster than 22.08% of C++ online submissions for Kth Largest Element in an Array.
    // Memory Usage: 10.9 MB, less than 7.46% of C++ online submissions for Kth Largest Element in an Array.
    int findKthLargestUseHeap(vector<int>& nums, int k) {
        int res;
        priority_queue<int> maxHeap;
        
        for (int i = 0; i < nums.size(); i++)
            maxHeap.push(nums[i]);

        for (int i = 0; i < k; i++) {
            res = maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }

    // 另外一个方式就是，我们只维护 k 个元素大小的堆，只不过此时为最小堆，这种方式可对海量数据进行求解，例如 1亿、10亿的数据量 (内存无法存储 nums 中的全部元素)
    // Runtime: 24 ms, faster than 49.67% of C++ online submissions for Kth Largest Element in an Array.
    // Memory Usage: 10.5 MB, less than 45.65% of C++ online submissions for Kth Largest Element in an Array.
    int findKthLargestUseHeapOptimization(vector<int>& nums, int k) {
        int res;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < nums.size(); i++) {
            if (minHeap.size() == k) {
                if (nums[i] > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
            else minHeap.push(nums[i]);
        }

        return minHeap.top();
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // return findKthLargestUseHeap(nums, k);
        return findKthLargestUseHeapOptimization(nums, k);
    }
};
