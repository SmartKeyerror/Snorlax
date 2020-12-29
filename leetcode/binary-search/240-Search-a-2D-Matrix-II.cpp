#include <vector>

using namespace std;

/*
 * 给定一个二维数组 matrix，该 matrix 每一行、每一列是有序的，但是第 i 行和第 i+1 行并不有序，和 74 号问题有明显区别
 * 
 * 我们可以从右上角的元素开始，如果查找的元素大于 matrix[0][n-1] 的话，往下走; 如果小于 matrix[0][n-1] 的话，往左走
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;

        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
