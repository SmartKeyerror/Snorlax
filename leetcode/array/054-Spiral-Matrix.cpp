
#include <vector>

using namespace std;

/*
 * 螺旋打印一个 m * n 的二维矩阵。
 * 
 * 通过实验模拟我们发现，起点为 [0, 0]、[1、1]、[2, 2] 等。
 * 
 * 第一圈儿为第 0 行，n - 1 - 0 列，m - 1 - 0 行，第 0 列 => 起点为 [0, 0]
 * 
 * 第二圈儿为第 1 行，n - 1 - 1 列，m - 1 - 1 行，第 1 列 => 起点为 [1, 1]
 * 
 * 第三圈儿为第 2 行，n - 1 - 2 列，m - 1 - 2 行，第 2 列 => 起点为 [2, 2]
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = n - 1, top = 0, bottom = m - 1, posi = 0;
        
        while (left <= right && top <= bottom) {
            
            // top
            for (posi = left; posi <= right; posi++) 
                result.push_back(matrix[top][posi]);
            top ++;

            // right
            for (posi = top; posi <= bottom; posi++) 
                result.push_back(matrix[posi][right]);
            right --;

            if (left > right || top > bottom) break;

            // bottom
            for (posi = right; posi >= left; posi--)
                result.push_back(matrix[bottom][posi]);
            bottom --;

            // left
            for (posi = bottom; posi >= top; posi--)
                result.push_back(matrix[posi][left]);
            left ++;
        }
        return result;
    }
};