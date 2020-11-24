#include <vector>

using namespace std;


/*
 * 求一个数组中和最大的连续子数组，一类典型的递推问题，问题本身不算太难，只是在数组元素的取值范围上有一个小陷阱
 * 
 * -2^31 <= nums[i] <= 2^31 - 1，也就是说，我们得使用 long long 类型来保存中间变量
 * 
 * [-2,1,-3,4,-1,2,1,-5,4]
 * 
 * 我们可以直接在原数组上进行操作，初始化时每个索引的子数组和就是它自身(也就是说只有一个元素的子数组)
 * 
 * 状态转移方程为: f(i) = max(f(i), f(i-1) + v(i))
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums[0];

        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max((long long)nums[i], (long long)nums[i] + nums[i-1]);
            result = max(result, nums[i]);
        }
        
        return result;
    }
};