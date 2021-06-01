
#include <vector>

using namespace std;

/*
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。

给定 target = 20，返回 false。

 * 因为对每一行、每一列都是升序的，所以我们可以从右上角出发: 
 * - 如果 target > matrix[0][n-1] 的话，那么 target 一定不在 matrix[0][n-1] 的左边，所以应该往下走
 * - 如果 target < matrix[0][n-1] 的话，那么 target 一定不在 matrix[0][n-1] 的下边，所以往左走
 * - 如果 target == matrix[0][n-1] 的话，直接返回结果
 * 
 * 这个问题可以和 74. Search a 2D Matrix 放到一起看: 
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties
 * - Integers in each row are sorted from left to right.
 * - The first integer of each row is greater than the last integer of the previous row.
 * 
 * 也就是说，在 74 号问题中，将 Matrix 一行一行追加的话，将会得到一个有序的一维数组，例如 
 * 
 * 1  3  5  7
 * 10 11 16 20
 * 23 30 34 60
 * 
 * 这不就相当于 “每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序” 吗? 所以这两个问题完全可以使用相同的代码来解答。
 * 
 * 这个问题也可以使用二分搜索来实现，只不过代码稍微复杂一些。
 * 
 * 首先使用一次二分搜索找到 target 所在行，然后再使用一次二分搜索找到所在列，时间复杂度 O(logm + logn) = O(log(m*n))，空间复杂度同样为 O(1)
 */


// 时间复杂度 O(m+n)，空间复杂度 O(1)。
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        if (matrix.empty()) return false;

        int m = matrix.size(), n = matrix[0].size();

        int i = 0, j = n-1;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j --;
            else i ++;
        }

        return false;
    }
};