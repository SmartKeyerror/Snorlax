


/*
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
 * 它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 * 
 * 这道题使用 DFS 或者是 BFS 都可以得到解决。
 * 
 * 一开始我觉得直接遍历这个二维数组，求出 x 和 y 的位数和，判断是否小于等于 K 即可，但是忽略了一个条件: 机器人从 [0, 0] 出发。
 * 
 * 也就是说，假如机器人不能够到达 [x-1][y] 或者是 [x][y-1] 的话，即使 [x][y] 满足位数和小于等于 K，它也没办法走过去。
 * 
 * 因为机器人想要最大话自己所能够到达的格子的话，那么一定是一直往右或者是往下走，有点儿像波面扩散，所以我们可以用 DP 的方式来思考
 * 
 * 如果当前 [x][y] 位数之和小于等于 K 的话，那么只要机器人能到 [x-1][y] 或者是 [x][y-1] 的话，那么它也一定能到 [x][y]
 * 
 */

#include <vector>

using namespace std;


class Solution {
private:
    int digitSum(int x) {
        if (x == 100) return 1;
        else if (x < 10) return x;
        return x % 10 + x / 10;
    }
public:
    int movingCount(int m, int n, int k) {
        int result = 0;

        vector<vector<bool>> dp(m, vector<bool>(n, false));

        dp[0][0] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (digitSum(i) + digitSum(j) > k) continue;
                if (i >= 1) dp[i][j] = dp[i][j] || dp[i-1][j];
                if (j >= 1) dp[i][j] = dp[i][j] || dp[i][j-1];
                if (dp[i][j]) result ++;
            }
        }

        return result;
    }
};