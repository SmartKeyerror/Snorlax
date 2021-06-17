#include <vector>

using namespace std;

/*
 * 在一个“有序”的二维数组中进行搜索，“有序”是指将 m x n 的这个二维数组逐行相接的话，得到的一维数组有序。
 * 
 * 使用两次二分搜索即可，第一次寻找所在的行，第二次在所在行中寻找对应的列。
 */ 
class Solution {
public:

    bool twiceBinarySearchSolution(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int left = 0, right = matrix.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target > matrix[mid].back()) left = mid + 1;
            else if(target < matrix[mid].front()) right = mid - 1;
            else break;
        }

        int row = mid;

        left = 0, right = matrix[mid].size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
    
    // 映射解法
    bool singleBinarySearchSolution(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int total = m * n;

        int left = 0, right = total - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int current = matrix[mid/n][mid%n];

            if (current == target) return true;
            else if (current > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return twiceBinarySearchSolution(matrix, target);
        return singleBinarySearchSolution(matrix, target);
    }      
};
