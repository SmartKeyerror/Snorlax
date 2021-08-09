
#include <vector>
#include <limits.h>

using namespace std;

/*
 * 给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 贪心: 对于 prices[i] 来说，假如当前买入，那么就应该在它上涨时卖出。
 * 
 * DP: 
 * 对于第 i 天而言，假如说我们想要卖出的话，那么手里必须得有股票；
 * 对于第 i 天来说，假如说我们想要买入的话，那么手里必须没有股票。
 * 
 * 因此，是否持有股票也必须作为状态添加到状态定义中。
 * 
 * dp[i][0] 表示第 i 天没有持有股票的最大利润，dp[i][1] 表示第 i 天持有股票的最大利润，那么就有:
 * 
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * 第 i 天不持有可由两种状态可以转移过来: 第 i - 1 天也不持有；第 i - 1天持有，但是今天卖了，因此会产生 prices[i] 的利润
 * 
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 * 第 i 天持有可由两种状态可以转移过来: 第 i - 1 天也持有；第 i - 1 天不持有，但是今天买入了，因此利润要减去今天的股票价格
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;

        if (prices.size() == 1) return 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i+1]) {
                result += prices[i+1] - prices[i];
            }
        }
        return result;
    }
};
