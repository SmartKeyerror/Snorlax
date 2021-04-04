#include <vector>
#include <cmath>
#include <climits>

using namespace std;


/*
 * 比较典型的贪心问题
 */
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int maxIndex = 0, maxDiff = 0;

        for (int i = 0; i < nums1.size(); i ++) {
            if (abs(nums1[i] - nums2[i]) > maxDiff) {
                 maxIndex = i;
                 maxDiff = abs(nums1[i] - nums2[i]);
            }
        }

        int minIndex = 0, minDiff = INT_MAX;

        for (int i = 0; i < nums1.size(); i ++) {
            if (abs(nums1[i] - nums2[maxIndex]) < minDiff) {
                 minIndex = i;
                 minDiff = abs(nums1[i] - nums2[maxIndex]);
            }
        }

        nums1[maxIndex] = nums1[minIndex];

        long long result = 0, mod = 1e9+7;

        for (int i = 0; i < nums1.size(); i ++) {
            result += (long long)abs(nums1[i] - nums2[i]);
        }

        return result  % mod;
    }
};