
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
    // 时间复杂度: O(n)，空间复杂度: O(1)
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int left = 0, sum = 0, result = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            // 当窗口满足条件时 left 指针需要主动的移动，以得到更小的窗口
            while (left < nums.size() && sum >= s) {
                result = min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};