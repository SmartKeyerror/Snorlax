
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * 给定一个正整数数组，判断该数组是否能够被分割成 2 个子数组，使得它们的和相同
 * 
 * 没有思路之前先尝试使用暴力解，首先我们求个 sum(nums)，然后计算 sum(nums) / 2
 * 如果结果为奇数的话，我们可以直接返回 false。
 * 否则，问题就变成了能否在 nums 中寻找 最多 nums.size() - 1 个元素，使得它们的和为 sum(nums) / 2
 * 这不就是 Combination Sum 问题吗? 排序+回溯+减枝，就能得到问题的解。
 * 
 * 回溯超时了，所以再来看 DP 解法
 * 
 * 本质上是一个 0-1背包 问题，当前的元素选还是不选都会影响最终的结果。
 * 
 * dp[i][j] 表示前 i 个元素中能否找到一个子集，满足和为 j。那么我们最终要计算的就是 dp[n][sum(num)/2]
 * 
 * 再来看 dp[i][j] 与 “历史数据” 之间的关系。
 * - 如果 j >= nums[i-1] 的话，dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
 * - 否则，dp[i][j] = dp[i-1][j]
 */
class Solution {

    // Time Limit Exceeded， 好吧，就算是使用减枝的回溯法也依然超时。
    // 但是回溯真的是一个可行解，有时候面试的时候脑子宕机，提交一个可行解总比提交一个“无解”要强的多
    // (MD超时就超时嘛，说这么一大堆挽个锤子的尊...
    bool backtrackingSolution(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) return false;
        sort(nums.begin(), nums.end());
        return backtracking(nums, target / 2, 0, 0);
    }

    bool backtracking(vector<int>& nums, int target, int index, int current) {
        if (current == target) return true;
        for (int i = index; i < nums.size(); i++) {
            if (current + nums[i] > target) break;
            current += nums[i];
            if (backtracking(nums, target, i + 1, current)) return true;
            current -= nums[i];
        }
        return false;
    }

    bool dpDolution(vector<int>& nums) {

        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) return false;
        target = target / 2;

        vector<bool> memory(target + 1, false);
        memory[0] = true;

        for (int i = 1; i <= nums.size(); i++)
            for (int j = target; j >= nums[i-1]; j--)
                memory[j] = memory[j] || memory[j-nums[i-1]];
    
        return memory[target];
    }


public:
    bool canPartition(vector<int>& nums) {
        // return backtrackingSolution(nums);
        return dpDolution(nums);
    }
};
