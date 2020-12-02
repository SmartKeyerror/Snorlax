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
        int minPrice = INT_MAX, bestProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            bestProfit = max(bestProfit, prices[i] - minPrice);
        }
        return bestProfit;
    }
};
