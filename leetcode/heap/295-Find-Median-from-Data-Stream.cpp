
#include <vector>
#include <queue>

using namespace std;

/*
 * 数据流中求百分位数问题，这题稍微简单一些，只要求中位数，两个堆的比例保持 1:1 就好
 * 
 * 同时维护一个大堆和一个小堆，并保持两个堆的数据量为 1:1，并记录添加进堆的数据总量 (total)
 * 
 * 当两个堆的数量相等时，我们将 num 添加至大堆中，并将大堆堆顶元素 pop 出来，丢进小堆中
 * 当两个堆的元素不相等时，将 num 添加进小堆中，并将小堆堆顶元素 pop 出来，丢进大堆中
 * 
 * 若 total 为偶数，那么 res = (最大堆堆顶元素值 + 最小堆堆顶元素值) / 2
 * 若 total 为奇数，那么 res = 最小堆堆顶元素值
 */
class MedianFinder {

private:

    int total = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (minHeap.size() == maxHeap.size()) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        total ++;
    }
    
    double findMedian() {
        if (total % 2 == 0)
            return (maxHeap.top() + minHeap.top()) / 2.0;       // 这里别忘了结果应为浮点数
        else
            return minHeap.top();
    }
};
