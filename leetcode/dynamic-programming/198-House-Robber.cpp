
#include <vector>

using namespace std;

class Solution {

private:

    vector<int> memory;

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

    // 状态定义: 尝试洗劫 [index...nums.size()-1] 之间的房屋，并返回最大洗劫数量
    int robInterval(vector<int>& nums, int index) {

        // 这里的条件是为了下面 robInterval(nums, index + 2) 所设置的, index + 2 可能会越界
        if (index >= nums.size())
            return 0;

        // 若 index 为最后一间房屋，没啥好说的，抢它!
        if (index == nums.size() - 1)
            return nums[index];
        
        if (memory[index] != -1)
            return memory[index];
        
        int res = 0;
        for (int i = index; i < nums.size(); i++) {
            // 情况分两种，我可以把当前房屋洗劫了，也可以不洗劫。如果洗劫了当前房屋，下一次能洗劫的房屋就为 index + 2
            // 下面的一行代码其实就是状态转移方程
            res = max3(res, nums[index] + robInterval(nums, index + 2), robInterval(nums, index + 1));
        }
        
        memory[index] = res;

        return res;
    }

public:

    // 自顶向下的递归实现
    int rob(vector<int>& nums) {

        memory = vector<int>(nums.size(), -1);

        return robInterval(nums, 0);
    }

    // 自底向上的递推实现
    int robDP(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0];

        vector<int> memory = vector<int>(nums.size(), 0);

        // 只有一间房屋时只能洗劫这一间
        memory[0] = nums[0];

        // 有两间房屋时，选择一间
        memory[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            // 对于第 i 间房屋而言，如果不选择洗劫，那么其最大收益值就是 memory[i-1]
            // 如果选择洗劫，那么最大值就是 nums[i] + memory[i-2]
            memory[i] = max(memory[i-1], nums[i] + memory[i-2]);
        }

        return memory[nums.size() - 1];
    }
};
