
#include <vector>
#include <limits.h>

using namespace std;

/*
 * 求所有乘积 小于 K 的连续子数组的个数
 * 
 * 相关题目: 
 *      152. Maximum Product Subarray
 *      325. Maximum Size Subarray Sum Equals k
 *      560. Subarray Sum Equals K 
 */
class Solution {
public:
    // 时间复杂度: O(n)，空间复杂度: O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, res = 0, product = 1;

        for (int right = 0; right < nums.size(); right++) {

            // 将当前值纳入窗口
            product *= nums[right];

            // 当窗口不满足条件时，收缩窗口
            while (left <= right && product >= k) {
                product /= nums[left];
                left ++;
            }
            
            // 此时以 nums[right] 为结尾的乘积小于 K 的连续子数组个数其实就是区间长度
            res += right - left + 1;
        }
        return res;
    }
};
