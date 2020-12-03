
#include <vector>
#include <queue>

using namespace std;

/*
 * 数据流中求百分位数问题，这题稍微简单一些，只要求中位数，两个堆的比例保持 1:1 就好
 * 
 * 同时维护一个大堆和一个小堆，并保持两个堆的数据量为 1:1，并记录添加进堆的数据总量 (total)
 */
class MedianFinder {

private:

    int total = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    // 重新平衡两个堆的元素
    void rebalance() {
        if (minHeap.size() + 1 < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if (maxHeap.size() + 1 < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (minHeap.empty() || num > minHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);
        rebalance();
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0 ;
        return minHeap.size() > maxHeap.size() ? minHeap.top(): maxHeap.top();
    }
};
