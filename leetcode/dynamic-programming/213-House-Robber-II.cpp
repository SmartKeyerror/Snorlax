
#include <vector>

using namespace std;


/*
 * 打家劫舍问题之第二版: 环形小镇中洗劫房屋 (下一次是不是去二叉树中或者是无向图中打家劫舍了 =_=)
 * 
 * 简单地来说，相较于普通的打家劫舍而言，环形小镇在偷了第一家之后，最后一家就不能偷; 如果没偷第一家，那么最后一家就能偷。
 * 
 * 之前问题的状态转移方程为: f(i) = max{ v(i) + f(i-2), f(i-1)}
 * 
 * 现在有了一个特殊状态: 洗劫第一个房间和不洗劫第一个房间，将直接影响到最后一个房间的洗劫，并且在上面的状态转移方程中，我们无法将该条件直接添加进去
 * 所以，干脆分成两种情况计算， 计算 nums[0...nums.size()-2] 以及 nums[1...nums.size()-1]，然后取它们的较大值
 */
class Solution {

    int robInterval(vector<int>& nums, int start, int end) {
        vector<int> memory = vector<int>(nums.size(), 0);

        memory[start] = nums[start];
        memory[start+1] = max(nums[start], nums[start+1]);

        for (int i = start + 2; i <= end; i++) {
            memory[i] = max(nums[i] + memory[i-2], memory[i-1]);
        }

        return memory[end];
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        
        return max(robInterval(nums, 0, nums.size() - 2), robInterval(nums, 1, nums.size() - 1));
    }
};
