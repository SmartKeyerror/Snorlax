
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> memory;

    int dfs(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        
        // 题目已给出 bad case 的返回值，就是 -1
        if (amount < 0)
            return -1;
        
        if (memory[amount] != -2)
            return memory[amount];
        
        int res = INT_MAX;
        
        // 相比于小青蛙，零钱兑换会有很多种找零方式。我们需要一个循环来遍历所有的选择(不只是跳1阶或者跳2阶)
        for (int i = 0; i < coins.size(); i++) {
            
            // 小青蛙需要的是所有的跳法，所以返回的是 f(n-1) + f(n-2)
            // 零钱找零则是需要用最少的硬币完成任务，那么其实就是 min{ f(n-coins[1]), f(n-coins[2]), f(n-coins[3], ...., f(n-coins[size-1])) }

            int sub = dfs(coins, amount - coins[i]);

            if (sub == -1)
                continue;

            res = min(res, sub + 1);
        }

        memory[amount] = res == INT_MAX ? -1: res;

        return memory[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        memory = vector<int>(amount + 1, -2);

        return dfs(coins, amount);
    }

    int coinChangeDP(vector<int>& coins, int amount) {
        vector<int> memo = vector<int>(amount + 1, INT_MAX);

        memo[0] = 0;

        // 对 coins 进行排序，便于剪枝
        sort(coins.begin(), coins.end());

        for (int currentAmount = 1; currentAmount < memo.size(); currentAmount++) {
            
            for (int c: coins) {

                if (currentAmount - c < 0)     // 此时可直接 break
                    break;

                if (memo[currentAmount-c] != INT_MAX)
                    memo[currentAmount] = min(memo[currentAmount], memo[currentAmount - c] + 1);

            }
        }
        return memo[amount] == INT_MAX ? -1: memo[amount];
    }
};
