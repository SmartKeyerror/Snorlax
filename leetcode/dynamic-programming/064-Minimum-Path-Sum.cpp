
#include <vector>

using namespace std;

/*
 * 二维平面中加权最短路径问题, 从左上到右下，并且每次只能向下或者向右移动， 和 62、63 号问题基本属于同一类问题
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        if (grid.size() == 0)
            return -1;

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result = vector<vector<int>>(m, vector<int>(n, 0));

        // 同样的，第 0 行和第 0 列只有一条路径可走，并且不会被刀(笑
        result[0][0] = grid[0][0];
        
        for (int i = 1; i < n; i++)
            result[0][i] = result[0][i-1] + grid[0][i];

        for (int j = 1; j < m; j++)
            result[j][0] = result[j-1][0] + grid[j][0];
        
        // 开始递推， f(m, n) = min(f(m, n-1), f(m-1, n)) + v(m, n)
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) 
                result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
            
        return result[m-1][n-1];
    }
};