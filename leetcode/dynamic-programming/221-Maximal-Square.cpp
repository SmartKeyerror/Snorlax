
#include <vector>

using namespace std;

/*
 * 给定一个仅包含 '0'、'1' 的二维数组，求出仅包含字符 '1' 的最大正方形
 * 
 * 讲实话，没想出来怎么做的，看了以下别人的解析，没有恍然大悟的感觉，只觉得: 还特喵的能这样?
 * 
 * DP 思路我觉得挺巧妙的，memory[i][j] 表示以 matrix[i][j] 为右下角的最大正方形的边，注意是边长，而不是面积。
 * 
 * 既然 memory[i][j] 为右下角，那么该点的右上、右边、右下、下面、左下这些节点都可以不用考虑了，只需要考虑左边、左上和上面这三个节点的值即可。
 * 
 * 如果 memory[i][j] 为 '0'，那么 memory[i][j] 就等于 0; 如果 memory[i-1][j], memory[i-1][j-1], memory[i][j-1] 其中有一个为 '0' 的话，
 * memory[i][j] 都不能构成包含 '1' 的正方形。所以，状态转移方程为: memory[i][j] = min(memory[i-1][j], memory[i-1][j-1], memory[i][j-1]) + 1
 * 
 * 除此以外，第 0 行和第 0 列需要单独考虑，因为这时候 i-1 或者是 j-1 都会越界。
 * 
 * 可以看到，这非常像 62. Unique Paths，只是换了一个形式。(对，换了一个壳我就不会了，战五渣无疑了...)
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        vector<vector<int>> memory(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                
                // 初始化第 0 行或第 0 列
                if (i == 0 || j == 0)
                    memory[i][j] = matrix[i][j] - '0';
                
                else if (matrix[i][j] == '1')
                    memory[i][j] = min(min(memory[i-1][j], memory[i-1][j-1]), memory[i][j-1]) + 1;
                
                res = max(res, memory[i][j]);
            }
        }
        return res * res;
    }
};
