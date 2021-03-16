
#include <vector>
#include <climits>

using namespace std;

/*
 * 🐸 跳石子问题。
 * 
 * 题目已经给出了必然能够到达最后石子，现在要求跳到最后一个石子上所需要的最小步数。
 * 
 * 假设最优解是从第 i 个石子上跳过来的，那么 f(n) = f(i) + 1, i + nums[i] >= n - 1，如此一来就得到了子问题。
 */
class Solution {
public:

    int intuitiveSolution(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] + j >= i)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n-1];
    }

    int jump(vector<int>& nums) {
        return intuitiveSolution(nums);
    }
};