
#include <vector>

using namespace std;


/*
 * 给你一个整数数组 nums （下标从 0 开始）和一个整数 k 
 * 
 * 一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1) 。一个 好 子数组的两个端点下标需要满足 i <= k <= j 
 * 
 * 请你返回 好 子数组的最大可能 分数 。
 * 
 * 输入：nums = [1,4,3,7,4,5], k = 3
 * 输出：15
 * 解释：最优子数组的左右端点下标是 (1, 5) ，分数为 min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15 。
 * 
 * 这道题和 11.Container With Most Water 有些类似，只不过 11 号问题是从两边儿向中心扩展。这道题则需要从中心向两边儿扩展
 */

class Solution {
public:
    // 时间复杂度: O(n)，空间复杂度: O(1)
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;

        int result = 0, n = nums.size();

        int minimum = INT_MAX;

        while (left >= 0 && right < n) {

            minimum = min(minimum, min(nums[left], nums[right]));

            result = max(result, minimum * (right - left + 1));

            // 边界条件处理
            if (left == 0) right++;
            else if (right == n - 1) left--;

            // 决定到底是左指针移动还是右指针移动
            else if (nums[left - 1] < nums[right + 1]) right++;
            else left--;
        }

        return result;
    }
};

/*
 * Lee 大佬的解法，优雅。
 */
class Solution {
public:
    int maximumScore(vector<int>& A, int k) {
        int res = A[k], mini = A[k], i = k, j = k, n = A.size();
        while (i > 0 or j < n - 1) {
            if ((i > 0 ? A[i - 1] : 0) < (j < n - 1 ? A[j + 1] : 0))
                mini = min(mini, A[++j]);
            else
                mini = min(mini, A[--i]);
            res = max(res, mini * (j - i + 1));
        }
        return res;
    }
};