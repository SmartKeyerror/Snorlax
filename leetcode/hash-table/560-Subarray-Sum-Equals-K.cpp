
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 求数组中和为 k 的连续子数组个数，单个元素也算“连续子数组”
 * 
 * 首先来看暴力解法，双层 for 循环，数组中的每一个元素都作为连续子数组的第一个元素，寻找和为 k 的子数组。
 * 但是 1 <= nums.length <= 2 * 10^4 这个限制杜绝了暴力解法的可能，一定会 TLE。
 * 
 * 除此以外，我们还可以使用 prefixSum 这个非常有用的技巧完成。prefixSum 其实就是 nums[0, i] 的和。由于起始点是固定的，所以
 * 我们只需要在一次遍历过程中，进行累加就能够得到 prefixSum(i) 的值。
 * 
 * 以数组 [1, 2, 3] 为例，其 prefixSum 分别为:
 *        1  3  6
 * 
 * 在有了 prefixSum 数组以后，我们就可以以 O(1) 的时间复杂度求出任意一段连续子数组的和了，例如:
 * 
 * sum[2, 2] = prefixSum(2) - prefixSum(1) = 6 - 3 = 3
 * sum[1, 2] = prefixSum(2) = prefixSum(0) = 6 - 1 = 5
 * 
 * 所以，sum[i, j] = prefixSum(j) - prefixSum(i-1)，sum[i, j] 均为闭区间
 * 
 * 那么得到这个东西有什么用呢? 如果我们将 sum[i, j] 换成是 k 的话，问题就变成了 k = prefixSum(j) - prefixSum(i-1)
 * 
 * 如此一来，问题就变成了另一种方式的 Two Sum，只不过这次我们要记录 prefixSum 在整个数组中出现的频次而已。
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // key: prefixSum, value: frequency of prefixSum
        // 当 i = 0的时候，prefixSum 为 0，此时也有一个频次
        unordered_map<int, int> frequency = {{0, 1}};

        int result = 0, prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            // 现在让我们看看 prefixSum - k 在 frequency 中的频率，这个频率就是一个结果
            result += frequency[prefixSum - k];
            frequency[prefixSum] ++;
        }
        return result;
    }
};
