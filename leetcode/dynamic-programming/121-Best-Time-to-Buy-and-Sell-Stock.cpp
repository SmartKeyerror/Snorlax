#include <vector>
#include <limits.h>

using namespace std;

/*
 * 股票买卖问题，并且只能买/卖一次，求最大收益
 * 
 * 虽然分类在 DP 标签下，但是我觉得这更是一个求最大值和最小值的问题。最小值时买入，最大值时卖出即可。
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, profit = 0;

        // 对于当前的 prices[i] 来说，能够获得的最大收益就是前面的最小买入价格，并在当前卖出
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                profit = max(profit, prices[i] - min_price);
            }
        }
        return profit;
    }
};
