
#include <vector>

using namespace std;

/*
 * 给定一个 nums 数组，求其最长子序列，使得任意子集间的相互取余结果为 0。
 * 
 * 例如 nums = [1,2,4,8], 最长子序列为 [1,2,4,8]，因为 2 % 1 = 0, 4 % 2 = 0, 8 % 4 = 0, 4 % 1 = 0, 8 % 1 = 0, 8 % 2 = 0。
 *
 * 本质上是一个 LIS 的问题，对于最后一个元素 K 来说，只要 K % nums[i] == 0，都可以尝试对其进行取值。 
 */
class Solution {
public:

    vector<int> largestSubset(vector<int>& nums) {
        int n = nums.size(), largest = 1;
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j]+1);
                    largest = max(largest, dp[i]);
                }
            }
        }
        // 还得找到那个最长的 subset 是由那些元素组成的，逆推回去，随便找一个就行
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == largest) {
                index = i;
                break;
            }
        }

        vector<int> result;
        result.push_back(nums[index]);
        largest --;

        while (largest > 0) {
            for (int i = 0; i < n; i++) {
                if (dp[i] == largest && result.back() % nums[i] == 0) {
                    result.push_back(nums[i]);
                    largest --;
                }
            }
        }
        return result;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        return largestSubset(nums);
    }
};