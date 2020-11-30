
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>

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

    int __partition(vector<int> &nums, int left, int right) {
        // 两路分片，只需要找到 < v 和 > v 的分界点即可

        // 随机选取锚定点，并将其置于当前子数组的首位
        swap(nums[left], nums[left+rand()%(right-left+1)]);

        int demarcation = left, v = nums[left];

        // nums[left+1...demarcation] < v, nums[demarcation+1, right] >= v
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < v) {
                demarcation ++;
                swap(nums[i], nums[demarcation]);
            }
        }
        swap(nums[left], nums[demarcation]);
        return demarcation;
    }

    int __selection(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];

        int pos = __partition(nums, left, right);

        if (nums.size() - k == pos)
            return nums[pos];
        else if (nums.size() - k > pos) 
            // 此时，我们应该去右边寻找
            return __selection(nums, pos + 1, right, k);
        else
            return __selection(nums, left, pos - 1, k);
        
    }

    // 最后，我们可以借助两路快排的方式来完成
    // Runtime: 16 ms, faster than 81.83% of C++ online submissions for Kth Largest Element in an Array.
    // Memory Usage: 10.3 MB, less than 88.36% of C++ online submissions for Kth Largest Element in an Array.
    int findKthLargestUsePartition(vector<int>& nums, int k) {
        srand(time(NULL));
        return __selection(nums, 0, nums.size() - 1, k);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        // return findKthLargestUseHeap(nums, k);
        // return findKthLargestUseHeapOptimization(nums, k);
        return findKthLargestUsePartition(nums, k);
    }
};
