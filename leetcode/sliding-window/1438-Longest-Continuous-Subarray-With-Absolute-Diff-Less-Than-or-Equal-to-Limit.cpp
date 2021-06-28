
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

/*
 * 一道比较典型的滑动窗口问题。在此题中，我们关心的是窗口中的最大值以及最小值，并且我们需要动态的更新窗口中的最大值和最小值。
 * 
 * 不管是使用 multiset 还是 map 来实现，其时间复杂度均为 O(nlogn)，空间复杂度为 O(n)
 * 
 * 除此以外，因为我们只对窗口的最大值和最小值感兴趣，所以也可以使用两个单调队列实现: 一个单调递增队列，一个单调递减队列
 * 
 * 此时时间复杂度为 O(n)，空间复杂度为 O(n)
 */
class Solution {
public:
    int multisetSolution(vector<int>& nums, int limit) {
        multiset<int> window;
        int n = nums.size(), result = 1, left = 0, right = 0;

        while (right < n) {
            window.insert(nums[right]);
            while (*window.rbegin() - *window.begin() > limit) {
                // 注意，这里不能写 window.erase(nums[left]), 这样会将值为 nums[left] 的所有元素从 window 中删除
                // 而我们的本意只是删除一个，所以用迭代器的方式实现
                window.erase(window.find(nums[left]));
                left ++;
            }
            result = max(result, right - left + 1);
            right ++;
        }
        return result;
    }

    int mapSolution(vector<int>& nums, int limit) {
        map<int, int> window;
        int result = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            window[nums[right]] ++;

            // 判断当前窗口是否满足要求
            while (window.rbegin()->first - window.begin()->first > limit) {
                window[nums[left]] --;
                if (window[nums[left]] == 0) window.erase(nums[left]);
                left ++;
            }

            // 此时窗口满足要求，更新结果
            result = max(result, right - left + 1);
        }
        return result;
    }

    int dequeueSolution(vector<int>& nums, int limit) {
        int result = 0;

        deque<int> maxQueue, minQueue;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            // 维护单调递增队列的性质 => 1, 4, 5, 8
            while (!maxQueue.empty() && nums[right] > maxQueue.back())
                maxQueue.pop_back();

            // 维护单调递减队列的性质 => 8, 5, 4, 1
            while (!minQueue.empty() && nums[right] < minQueue.back())
                minQueue.pop_back();
            
            maxQueue.push_back(nums[right]);
            minQueue.push_back(nums[right]);

            // 此时不满足题目要求
            while (!minQueue.empty() && !maxQueue.empty() && maxQueue.front() - minQueue.front() > limit) {
                if (minQueue.front() == nums[left]) minQueue.pop_front();
                if (maxQueue.front() == nums[left]) maxQueue.pop_front();
                left ++;
            }

            // 此时窗口满足要求，更新结果
            result = max(result, right - left + 1);
        }
        return result;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        // return multisetSolution(nums, limit);
        // return mapSolution(nums, limit);
        return dequeueSolution(nums, limit);
    }
};