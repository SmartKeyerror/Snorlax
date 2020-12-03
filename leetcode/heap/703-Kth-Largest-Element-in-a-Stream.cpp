
#include <vector>
#include <queue>

using namespace std;


/*
 * 在一个流中求第 K 大的元素，非常标准的堆的应用
 * 
 * 我们只需要维护一个大小为 k 的最小堆即可，为什么是最小堆呢? 
 * 
 * 原因在于当我们从流中插入一个元素时，需要和当前堆中的最小元素进行比较，如果该元素比最小值还要小的话，直接丢弃不用
 * 否则，我们需要弹出最小值元素，将新的元素添加到堆中，从而维护 Top-K 的堆的性质
 */
class KthLargest {
private:

    int kth;
    priority_queue<int, vector<int>, greater<int>> topKHeap;

public:

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int i = 0; i < nums.size(); i++) {
            topKHeap.push(nums[i]);
            if (topKHeap.size() > k) topKHeap.pop();
        }
    }
    
    int add(int val) {
        topKHeap.push(val);
        if (topKHeap.size() > kth) topKHeap.pop();
        return topKHeap.top();
    }
};
