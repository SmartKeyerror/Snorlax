
#include <vector>
#include <queue>

using namespace std;

/*
 * 使用单调双端队列完成，保证从队首到队尾是单调递减的。
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qmax;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            while (!qmax.empty() && nums[qmax.back()] <= nums[i]) 
                qmax.pop_back();

            qmax.push_back(i);

            if (qmax.front() < i - k + 1) qmax.pop_front();

            if (i >= k - 1) result.push_back(nums[qmax.front()]);
        }
        
        return result;
    }
};