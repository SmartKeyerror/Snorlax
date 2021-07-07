
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定不同的子数组为好子数组。
 * 
 * （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
 * 
 * 返回 A 中好子数组的数目。
 * 
 * 输入：A = [1,2,1,2,3], K = 2
 * 输出：7
 * 解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
 * 
 * 该问题和 "给定一个正数数组A[]，以及一个正整数 k，求乘积小于 k 的子数组的个数" 非常之类似，只不过这里求的是区间内不同元素的数量。
 * 
 * 如果我们使用单一的双指针策略来解决的话，以 [1,2,1,2,3] 取最长区间为例:
 * 
 * [1,2,1,2,3]
 *  ↑       ↑
 * left    right
 * 
 * 若 k = 2，那么当我们的 right 指针到达最后一个元素时，窗口不满足条件了，
 * 
 * 按照滑动窗口的“套路”来说，我们需要收缩窗口，也就是让 left++，直到窗口重新满足条件。
 * 
 * 最终，left 指针会指向 right 指针的前一个元素，得到了另一个满足条件的窗口。这是求满足条件最长区间的策略，无法求出满足条件的所有区间。
 * 
 * 而对于 713. 乘积小于K的子数组 这道题来说，以 [1,2,1,2,3], k = 2 为例，首先我们找到最长的满足条件的区间，也就是:
 * 
 * [1,2,1,2,3]
 *  ↑   ↑
 * left right
 * 
 * 此时最长区间为 [1, 2, 1]，以 right 为右边界，满足题意的区间个数为:
 * 
 * - [1, 2, 1]
 * -    [2, 1]
 * -       [1]
 * 
 * 这不就是 right - left + 1 吗?
 * 
 * 而这道好数组的解题关键就在于: 恰好由 K 个不同整数的子数组的个数 = 最多由 K 个不同整数的子数组的个数 - 最多由 K - 1 个不同整数的子数组的个数
 */

class Solution {
private:
    int subarraysWithMostKDistinct(vector<int>& nums, int k) {
        int result = 0;
        int left = 0;

        unordered_map<int, int> window;

        for (int right = 0; right < nums.size(); right++) {
            // 将当前值纳入窗口
            window[nums[right]] ++;

            // 窗口不满足条件时收缩窗口
            while (window.size() > k) {
                window[nums[left]] --;
                if (window[nums[left]] == 0)
                    window.erase(nums[left]);
                left ++;
            }

            result += right - left + 1;
        }
        return result;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithMostKDistinct(nums, k) - subarraysWithMostKDistinct(nums, k-1);
    }
};
