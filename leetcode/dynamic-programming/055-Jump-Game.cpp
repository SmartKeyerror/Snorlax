
#include <vector>
#include <memory>

using namespace std;

/*
 * 一道很经典的 dp 问题，🐸 跳石子。
 * 
 * 假设 nums 数组的长度为 n，那么小 🐸 最后必然调到 n-1 个石子，并且假设它是从第 i 个石子跳过来的，那么此时需要满足:
 * 
 * - 小青蛙能够跳到第 i 个石子
 * - i + nums[i] >= n - 1，也就是小 🐸 可以从第 i 个石子跳到 n-1 个石子。
 * 
 * 如此一来，我们就找到了子问题: 小青蛙能够跳到第 i 个石子，同时也得到了基本条件: i + nums[i] >= n - 1
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];

        // 🐸 从这里出发，所以第 0 个石子必然为 true
        dp[0] = true;

        for (int i = 1; i < n; i++) {
            dp[i] = false;
            for (int j = 0; j < i; j++) {
                if (nums[j] + j >= i)
                    dp[i] = dp[i] || dp[j];
                if (dp[i]) break;
            }
        }
        return dp[n-1];
    }
};