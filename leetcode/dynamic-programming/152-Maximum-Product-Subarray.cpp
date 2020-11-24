
#include <vector>

using namespace std;

/*
 * 和 53 号问题基本一样，只不过连续子数组的最大和改为了连续子数组的最大乘积
 * 
 * 乘积和求和问题最大的不同就是我们不能简单的使用 f(i) = max(f(i), f(i-1) * v(i)) 来实现，这是因为乘法中负负得正，例如 -2， 4， -5，结果为40
 * 
 * -2，3，-4，5，-6，7，-8，9
 * 
 * 所以说，我们还得记录一个最小值，以应对后续出现的负数相乘的情况
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() <= 1) return nums[0];

        int maxRes = nums[0], minRes = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = maxRes;
            maxRes = max(nums[i], max(nums[i] * maxRes, nums[i] * minRes));
            minRes = min(nums[i], min(nums[i] * temp, nums[i] * minRes));
            result = max(result, maxRes);
        }
        
        return result;
    }
};