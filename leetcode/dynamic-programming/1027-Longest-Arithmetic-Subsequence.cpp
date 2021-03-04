
#include <vector>

using namespace std;

/*
 * 求最长的 arithmetic 子序列，什么是 arithmetic 子序列呢? 就是相邻元素间的差值都等于某个常数 K。例如 [1, 5, 9, 13] 或者是 [13, 9, 5, 1]
 * 
 * 这和 LIS 问题基本类似。只不过这里的常数 K 题目是没有给出来的，所以需要作为一个状态进行记录。
 * 
 * 也就是说，对于第 i 个元素来说，它和之前的元素差值可能是 -500，-499，-498，.....，0，1，2，...，500，我们要分别取这些差值作为 K 的值，来计算最长 arithmetic 子序列。
 * 
 * 因为 K 有可能是负数，所以对于每一个 K，都加上 500 的偏移量 (A[i] <= 500)。
 * 
 * 设 dp[i][k] 为第 i 个元素为结尾的，且差值为 k 的最长 arithmetic 子序列的长度。
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), result = 0;
        vector<vector<int>> dp(n, vector<int>(1001, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int different = A[j] - A[i] + 500;
                if (dp[j][different] == -1) dp[i][different] = max(dp[i][different], 2);
                else dp[i][different] = max(dp[i][different], dp[j][different] + 1);
                result = max(result, dp[i][different]);
            }
        }
        return result;
    }
};