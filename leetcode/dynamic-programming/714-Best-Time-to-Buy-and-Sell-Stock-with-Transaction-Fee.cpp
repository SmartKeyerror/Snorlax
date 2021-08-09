

#include <vector>
#include <limits.h>

using namespace std;

/*
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
 * 
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 
 * 返回获得利润的最大值。
 * 
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 * 
 * 对于第 i 天而言，假如说我们想要卖出的话，那么手里必须得有股票；
 * 对于第 i 天来说，假如说我们想要买入的话，那么手里必须没有股票。
 * 
 * 因此，是否持有股票也必须作为状态添加到状态定义中。
 * 
 * dp[i][0] 表示第 i 天没有持有股票的最大利润，dp[i][1] 表示第 i 天持有股票的最大利润，那么就有:
 * 
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee)
 * 第 i 天不持有可由两种状态可以转移过来: 第 i - 1 天也不持有；第 i - 1天持有，但是今天卖了，因此会产生 prices[i] - fee 的利润
 * 
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 * 第 i 天持有可由两种状态可以转移过来: 第 i - 1 天也持有；第 i - 1 天不持有，但是今天买入了，因此利润要减去今天的股票价格
 */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

        // 初始化
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};

// 空间优化
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int not_hold = 0, hold = 0 - prices[0];

        for (int i = 1; i < n; i++) {
            not_hold = max(not_hold, hold + prices[i] - fee);
            hold = max(hold, not_hold - prices[i]);
        }
        return not_hold;
    }
};