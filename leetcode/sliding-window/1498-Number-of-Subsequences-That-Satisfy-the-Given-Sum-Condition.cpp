
#include <vector>
#include <set>
#include <cmath>

using namespace std;


/*
 * 求 nums 数组中连续子序列中最大值 + 最小值 <= target 的子序列个数，一道比较典型的 Sliding Window 问题。
 * 
 * 因为我们要求的是子序列，而不是子数组，所以可以对 nums 进行排序处理。
 * 
 * 假设当前的窗口内容为 [2, 3, 4, 5]，target = 100，所有的子序列都满足要求，此时存在 2^4 - 1 = 15 个子序列。 
 * 
 * 考虑重复计算的问题，当我们的窗口为 [2, 3] 时不应该更新 result，而是等到窗口不再满足要求时再更新。
 * 
 * 因此，我们可考虑在运行过程中不断地收缩窗口。
 */

#define MOD 1000000007

class Solution {
public:

    int bigPow(int v, int p) {
        if(p == 0) return 1;
        if(p == 1) return v;
        int h{bigPow(v, p>>1)}, f{(int)(((int64_t)h * h) % MOD)};
        return p&1 ? (f * v) % MOD : f;
    }

    int numSubseq(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size(), right = n - 1;

        sort(nums.begin(), nums.end());
        
        for (int left = 0; left < n; left ++) {
            // Shrink Window from right.
            while (left <= right && nums[left] + nums[right] > target) right --;
            if (left <= right) result = (result + bigPow(2, right - left)) % MOD;
        }
        return result;
    }
};