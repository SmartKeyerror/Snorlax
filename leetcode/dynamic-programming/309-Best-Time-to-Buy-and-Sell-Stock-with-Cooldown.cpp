
#include <vector>

using namespace std;

/*
 * 买卖股票的最佳时机并且带有冷静期，冷静期为 1 天，即假如当天卖出股票之后，第二天无法购买股票。
 * 
 * 按照原有的套路，可以假设:
 * - dp[i][0] 表示第 i 天不持有股票的最大利润，且不在冷静期内
 * - dp[i][1] 表示第 i 天不持有股票的最大利润，且处于冷静期内
 * - dp[i][2] 表示第 i 天持有股票的最大利润
 * 
 * 那么就有:
 * - dp[i][0] = max(dp[i-1][0], dp[i-1][1])，即要么第 i - 1 天也没有持有股票，或者是第 i - 1 天刚好是冷冻期的最后一天
 * - dp[i][1] = dp[i-1][2] + prices[i];
 * - dp[i][2] = max(dp[i-1][0] - prices[i], dp[i-1][2]);
 * 
 * 状态转移会稍微有点儿绕
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        // init
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][2] + prices[i];
            dp[i][2] = max(dp[i-1][0] - prices[i], dp[i-1][2]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};