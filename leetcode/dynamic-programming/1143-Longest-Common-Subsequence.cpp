
#include <string>
#include <vector>

using namespace std;


/*
 * 求两个字符串的最长公共子序列，一道非常典型的 DP 问题。
 * 
 * 既然有两个 string 进行进行，那么 dp 数组就设置成二维的。 dp[i][j] 表示 text1 中 [0...i] 以及 text2 中 [0...j] 最长公共子序列长度。
 * 
 * 现在来看如何使用“历史数据”推导出 dp[i][j]。如果 text1[i] == text2[j] 的话，那么不用多说，dp[i][j] = dp[i-1][j-1] + 1。
 * 
 * 问题在于如果 text1[i] != text2[j] 的话，结果如何更新。此时需要取 dp[i-1][j] 和 dp[i][j-1] 之间的较大值。
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i < n1 + 1; i++) {
            for (int j = 0; j < n2 + 1; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};