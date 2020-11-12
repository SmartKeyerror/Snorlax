
#include <vector>
#include <limits.h>

using namespace std;


/*
 * 在 nums 数组中找到最短的连续子数组，使得其 sum 值大于等于 s
 * 
 * 思路比较简单，维护一个持续向右滑动的窗口，窗口大小并不固定，记为 left, right
 * 
 * 如果 sum(left, right) 小于 sum 的话，说明窗口太小了，得加点儿元素进来，所以我们使 right 向右滑动，即 right++
 * 
 * 如果 sum(left, right) 大于 sum 的话，说明窗口有点儿大了，需要减少一些元素，所以我们使 left 向右滑动，即 left++
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        if (nums.size() == 0)
            return 0;
        
        // 起始时 sum 应该为0，那么该窗口应该不包含任何元素，所以 right 应为 -1
        int sum = 0;
        int left = 0; int right = -1;

        // 求最短路径，所以使用 INT_MAX 作为 res 的初始值
        int res = INT_MAX;

        while ( left <= nums.size() - 1) {
            if (right + 1 < nums.size() && sum < s) {
                right ++;
                sum += nums[right];
            } else {
                sum -= nums[left];
                left++;
            }

            if (sum >= s)
                res = min(res, right - left + 1);
        }

        return res == INT_MAX ? 0: res;
    }
};