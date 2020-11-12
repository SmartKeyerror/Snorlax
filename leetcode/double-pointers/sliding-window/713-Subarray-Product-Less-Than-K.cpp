
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, res = 0, product = 1;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            while (left <= right && product >= k) {
                product /= nums[left];
                left ++;
            }
            
            res += right - left + 1;
        }
        return res;
    }
};
