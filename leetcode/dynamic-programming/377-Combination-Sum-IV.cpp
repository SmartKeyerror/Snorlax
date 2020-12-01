
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 给定一个 nums 数组，其中的元素可以使用任意多次，输出和为 target 的全部组合数量
 * 
 * CoinChange、小青蛙跳台阶问题的另一个载体，可见 CoinChange、小青蛙跳台阶问题的本质有多么重要...
 * 
 * 该题要求输出全部的组合数量，而不是“最小”数量，所以说，回溯法也能够解决这个问题
 * 
 */
class Solution {
private:

    int topToDown(vector<int>& nums, int target, vector<int> &memory) {
        if (target < 0) return 0;
        if (target == 0) return 1;

        if (memory[target] != -1)
            return memory[target];

        int res = 0;
        for (int num: nums)
            res += topToDown(nums, target - num, memory);
        memory[target] = res;
        return res;
    }

    // 自顶向下的记忆化搜索实现
    // Runtime: 4 ms, faster than 66.05% of C++ online submissions for Combination Sum IV.
    int memorySearch(vector<int>& nums, int target) {
        vector<int> memory = vector<int>(target + 1, -1);
        return topToDown(nums, target, memory);
    }

    // 自底向上的递推实现
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum IV.
    int bottomToUp(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> memory = vector<unsigned int>(target + 1, 0);
        
        memory[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num: nums) {
                if (num > i) break;
                memory[i] += memory[i-num];
            }
        }
        return memory[target];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        // return memorySearch(nums, target);
        return bottomToUp(nums, target);
    }
};
