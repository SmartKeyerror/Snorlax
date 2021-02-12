
#include <vector>
#include <climits>

using namespace std;

/*
 * 求环形数组中连续子数组的最大和。
 * 
 * 既然是环形数组，那么我们就需要分 2 种情况进行讨论，正如同 Hint 中提到的一样。
 * 
 * - max sum subarray 就在原有数组中，并不涉及首位相连的部分，此时的最大数组和就是 DP 得到的结果。
 * 
 * - max sum array 出现在头尾相连的子数组中，那么此时我们就需要用数组的所有元素和减去中间那最小的一部分，这样才能得到首位相连的最大值。
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0, currentMax = 0, currentMin = 0;
        int caseMax = INT_MIN, caseMin = INT_MAX;

        for (auto num : A) {
            sum += num;
            currentMax = max(currentMax + num, num);
            currentMin = min(currentMin + num, num);
            caseMax = max(caseMax, currentMax);
            caseMin = min(caseMin, currentMin);
        }

        return sum - caseMin ? caseMax : max(caseMax, sum - caseMin);
    }
};