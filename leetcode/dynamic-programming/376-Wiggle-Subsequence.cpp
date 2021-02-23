
#include <vector>

using namespace std;


/*
 * 求 nums 数组中的 Longest Wiggle Subsequence， 这和 Longest Increasing Subsequence， 有着异曲同工之妙，但是要比 LIS 问题稍微复杂一些。
 * 
 * 因为 Wiggle Subsequence 可能是 升-降-升，也可能是 降-升-降，所以 dp 数组必须是一个二维数组: 
 * 
 * dp[i][0] 表示以当前元素为结尾的，并且最后一位为升序的最长子序列长度，例如 [2, 1, 5], dp[2][0] 就表示以元素 5 为结尾的、最后一位为升序的 Longest Wiggle Subsequence Length.
 * 
 * dp[i][1] 表示以当前元素为结尾的，并且最后一位为降序的最长子序列长度，例如 [1, 7, 5], dp[2][0] 就表示以元素 5 为结尾的、最后一位为降序的 Longest Wiggle Subsequence Length.
 * 
 * dp[i][0] 只关心 dp[i-k][1] 是否小于其自身，而 dp[i][1] 则只关心 dp[i-k][0] 是否大于其自身。
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), result = 0;
        vector<vector<int>> dp(n, vector<int>(2, 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                else if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                result = max(dp[i][0], dp[i][1]);
            }
        }
        return result;
    }
};