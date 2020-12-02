
#include <vector>
#include <limits.h>

using namespace std;

/*
 * 求二维数组下降的最短路径，起始点可以是第 0 行的任意一个节点，下降规则为列数不超过 1。和 120. Triangle 非常相似
 * 
 * memory[i][j] 一共能“接收” 3 个方向的下降，分别为左上(memory[i-1][j-1])、上面(memory[i-1][j])和右上(memory[i-1][j+1])
 * 所以，状态转移方程为: memory[i][j] = min{ memory[i-1][j-1], memory[i-1][j], memory[i-1][j+1]) + A[i][j]，边界情况特殊讨论
 * 
 * 最小下降路径将在最后一行产生。
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {

        int res = INT_MAX, m = A.size(), n = A[0].size();

        vector<vector<int>> memory = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0)
                    memory[i][j] = A[i][j];

                else if (j == 0)
                    memory[i][j] = min(memory[i-1][j], memory[i-1][j+1]) + A[i][j];
                
                else if (j == n - 1)
                    memory[i][j] = min(memory[i-1][j-1], memory[i-1][j]) + A[i][j];
                
                else
                    memory[i][j] = min(min(memory[i-1][j-1], memory[i-1][j]), memory[i-1][j+1]) + A[i][j];

                if (i == m - 1) 
                    res = min(res, memory[i][j]);
            }
        }
        return res;
    }
};
