
#include <vector>
#include <algorithm>

using namespace std;

/*
 * prefixSum 问题的另一个变种，求连续子数组和的绝对值的最大值。
 * 
 * 首先我们求出 prefixSum 数组，得到 prefixSum 数组之后，现在的问题就变成了寻找 i, j（i < j），使得 abs(prefixSum[j] - prefixSum[i]) 有最大值
 * 
 * 用 prefixSum 中的最小值减去 prefixSum 中的最大值，得到一个备选答案。然后再和 prefixSum 中的最小值的绝对值、最大值进行比较，得到最终的答案。
 * 
 */
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        int maxNbr = nums[0], minNbr = nums[0];

        for (int i = 1; i< n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
            maxNbr = max(maxNbr, prefixSum[i]);
            minNbr = min(minNbr, prefixSum[i]);
        }

        int res = max(abs(minNbr), maxNbr);
        res = max(res, abs(minNbr - maxNbr));

        return res;
    }
};