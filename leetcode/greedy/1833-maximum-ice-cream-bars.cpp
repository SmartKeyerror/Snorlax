
#include <vector>

using namespace std;

/*
 * 夏日炎炎，小男孩 Tony 想买一些雪糕消消暑。
 * 
 * 商店中新到 n 支雪糕，用长度为 n 的数组 costs 表示雪糕的定价，其中 costs[i] 表示第 i 支雪糕的现金价格。Tony 一共有 coins 现金可以用于消费，他想要买尽可能多的雪糕。
 * 
 * 给你价格数组 costs 和现金量 coins ，请你计算并返回 Tony 用 coins 现金能够买到的雪糕的 最大数量 。
 * 
 * 注意：Tony 可以按任意顺序购买雪糕。
 * 
 * 下面给出通用的 DP 解法，但是不适用于这道题目，因为这道题可以用贪心的思想来解决。
 * 
 * 这道题可以很好的说明 DP 和贪心之间的区别，贪心在某种程度上是 DP 的一个子集
 * 
 */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        vector<vector<int>> dp(n + 1, vector<int>(coins + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= coins; j++) {
                // j 块硬币买不起当前的雪糕，那么此时能买到的最大雪糕数就是前 dp[i-1][j]
                if (costs[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-costs[i-1]] + 1);
            }
        }

        return dp[n][coins];
    }
};

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int result = 0;

        for (int i = 0; i < costs.size(); i++) {
            if (coins >= costs[i]) {
                result ++;
                coins -= costs[i];
            }
            else break;
        }
        return result;
    }
};