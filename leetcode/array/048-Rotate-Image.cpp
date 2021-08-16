
#include <vector>

using namespace std;

/*
 * 顺时针旋转图像 90°，在日常的图片预览等应用中使用非常频繁。
 * 
 * 5  1  9  11
 * 2  4  8  10
 * 13 3  6  7
 * 15 14 12 16
 * 
 * 将会得到 
 * 
 * 15 12  2  5
 * 14  3  4  1
 * 12  6  8  9
 * 16  7 10  11
 * 
 * 第一行的元素会出现在最后一列，并且每一列的行数和原来的列数是相等的。第二行的元素会出现在倒数第二列，并且每一列的行数和原来的列数是相等的。
 * 
 * 所以假设我们有一个辅助数组 new_matrix 的话，就有 matrix[row][col] = new_matrix[col][n-1-row]。
 * 
 * 这个问题我们可以先水平翻转，然后再基于主对角线翻转。水平翻转其实就是把最后一行和第一行置换，倒数第二行和第二行置换:
 * 
 * matrix[row][col] => matrix[n-1-row][col]
 * 
 * 主对角线翻转其实就是将原来的行变成列，将原来的列变成行:
 * 
 * matrix[row][col] => matrix[col][row]
 * 
 * 最终有:
 * 
 * matrix[row][col] => matrix[n-1-row][col] => matrix[col][n-1-row]，也就得到我们最开始的那个公式
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 水平翻转,matrix[row][col] = matrix[n-1-row][col]
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }

        // 基于主对角线翻转, matrix[row][col] => matrix[col][row]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};