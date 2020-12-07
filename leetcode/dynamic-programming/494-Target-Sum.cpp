
#include <vector>
#include <numeric>

using namespace std;

/*
 * 给 nums 中的数字之前添加正负号，使得总和为 S
 * 
 * 对于每一个数字而言，我们有两个选择: 将其变为负数或者什么都不做(nums为非负整数)
 * 
 * 因为每次只有两个选择，所以这是一棵二叉树的深度优先遍历，状态转移方程不是很明确，所以首先使用自顶向下的递归实现
 */
class Solution {
private:

    // Runtime: 1668 ms, faster than 5.12% of C++ online submissions for Target Sum.
    // 无记忆化搜索的方案
    int topDown(vector<int>& nums, int &S, int index, int sum) {
        if (index == nums.size())
            return sum == S ? 1: 0;
        
        int count = 0;
        count += topDown(nums, S, index + 1, sum + nums[index]);
        count += topDown(nums, S, index + 1, sum - nums[index]);
        return count;
    }

    // 优化重复子问题
    vector<vector<int>> memory;

    // Runtime: 56 ms, faster than 55.80% of C++ online submissions for Target Sum.
    int memorySearch(vector<int>& nums, int &S, int index, int sum, int &offset) {
        if (index == nums.size())
            return sum == S ? 1: 0;
        
        if (memory[index][offset + sum] != -1) return memory[index][offset + sum];

        int count = 0;
        count += memorySearch(nums, S, index + 1, sum + nums[index], offset);
        count += memorySearch(nums, S, index + 1, sum - nums[index], offset);

        memory[index][offset + sum] = count;
        return count;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return topDown(nums, S, 0, 0);


        // 这里有个细节，S 可能为负数，所以得想个办法将其转换成正的索引
        // The sum of elements in the given array will not exceed 1000.
        // 题目下面儿的约束给出了 nums 总和不会超过 1000, 那么也就是说，S 最小值应该也是 1000， 谨慎起见，还是加个判断

        if (S < 0 && (0 - S) > 1000) return 0;

        int offset = 1000;
        memory = vector<vector<int>>(nums.size(), vector<int>(offset * 2 + 1, -1));
        return memorySearch(nums, S, 0, 0, offset);
    }
};
