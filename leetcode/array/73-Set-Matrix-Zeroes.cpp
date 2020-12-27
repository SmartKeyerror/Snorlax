
#include <vector>

using namespace std;

/*
 * 给定一个 m x n 的二维数组，找到包含元素 0 的所有行和列，并将该行还该列的元素全部替换成 0。
 * 有点儿像 QQ堂 里面💣爆炸的效果，💣爆炸以后水平和垂直方向上的物品、人物全部清空。
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> rowZeroes, colZeroes;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (matrix[i][j] == 0) {
                    rowZeroes.push_back(i), colZeroes.push_back(j);
                }

        // fill row
        for (int row : rowZeroes)
            fill(matrix[row].begin(), matrix[row].end(), 0);
        
        // fill column
        for (int col : colZeroes)
            for (int i = 0; i < m; i++)
                // 对每一行的第 col 列进行 fill zero
                matrix[i][col] = 0;
    }
};