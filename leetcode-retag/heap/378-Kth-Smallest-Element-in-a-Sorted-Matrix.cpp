
/*
 * Given an n x n matrix where each of the rows and columns are sorted in ascending order, 
 * return the kth smallest element in the matrix.
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
 * 
 * 这道题最直观的解法仍然是使用 heap，由于要求第 K 小的元素，所以我们使用一个大堆顶即可，同时也是 C++ priority_queue 的默认值。
 * 
 * 同时我们注意到整个 matrix 矩阵是严格有序的，那么我们就可以使用二分搜索的方式来完成。
 * 
 * 我们以 [1, 5, 9, 10, 11, 13] 这个一维数组来求第 3 小的元素为例，当然，假设这里并不能使用 nums[2] 来直接获取 _(:з」∠)_
 * 
 *  1, 5, 9, 10, 11, 13
 *  ↑                 ↑         => 初始状态时 left = 1, right = 13, 那么 mid = left + (right - left) / 2，也就是 7
 * left             right
 * 
 * 当我们得到了 mid = 7 以后，需要在 nums 数组中看看有多少个元素比 7 还要小（包含等于），我们可以使用 upper_bound() 函数来完成：
 * 
 * 即找到第一个比 7 大的元素索引，在 nums 数组中为 2，也就是说，有 2 个元素比 7 要小。
 * 
 * 而我们要求的是第 3 小的元素，但是现在我们得到了前 2 个小的元素，所以第 3 小的元素一定不在 1，5 里面，我们需要在 [mid+1, right] 中继续去寻找
 * 
 * 1, 5, 9, 10, 11, 13
 *      ↑           ↑           => 此时 left = 8，right = 13，也就是 left 并不在 nums 数组中，那么 mid = left + (right - left) / 2，也就是 10
 *     left        right
 * 
 * 得到 mid = 10 以后，看看有多少个数比 10 要小（包含等于），很明显有 4 个数比 10 要小，4 > 3，所以我们调整右区间，使 right = mid。
 * 
 * 那么 left = 8, right = 10, 得到 mid = 9，小于等于 9 的元素有 3 个，所以我们调整 right 区间，即 right = mid，也就是 9
 * 
 * 那么 left = 8, right = 9，得到 mid = 8，小于等于 8 的元素有 2 个，所以调整 left 区间，即 left = mid，也就是 9
 * 
 * 此时 left == right == 9，那么这就是最终的答案
 */

#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


// 时间复杂度为 O(nlogn * logD)，其中 D 为最大值和最小值之间的差值
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];

        while (left < right) {
            int mid = left + (right - left) / 2, count = 0;

            // 对于每一行我们都需要计算有多少个元素小于等于 mid
            for (int i = 0; i < n; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};