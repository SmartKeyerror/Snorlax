
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


/*
 * 这可能是最简单的难度为 hard 的题目了。双层 for 循环求出每一对 pair 的绝对值，丢到大小为 k 的小堆中即可。
 * 
 * 然而，heap 的实现 TLE 了。
 * 
 * TODO: use binary-search.
 */
class Solution {
private:
    // TLE
    int heapSolution(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (heap.size() == k ) {
                    if (abs(nums[i] - nums[j]) < heap.top()) {
                        heap.pop();
                        heap.push(abs(nums[i] - nums[j]));
                    }
                } else
                    heap.push(abs(nums[i] - nums[j]));
            }
        }
        return heap.top();
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        return heapSolution(nums, k);
    }
};