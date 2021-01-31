
#include <vector>

using namespace std;

/*
 * 给定两个有序数组，求两个数组的中位数，并且在 log(m+n) 的时间复杂度内解决。
 * 
 * 首先来看中位数的定义，在一个有序数组中，若其长度为偶数，那么中位数为第 n/2 和 n/2 - 1 个数的平均值。若 n 为奇数，那么就是第 n/2 个数。
 * 
 * 如果不考虑时间复杂度如何解决，两个有序数组，可以按照归并排序的 merge 过程进行归并，然后找到归并数组中的中位数，时间复杂度为 O(m+n)，空间复杂度 m+n.
 * 
 * 既然需要 log(m+n) 的时间复杂度解决，那么必然需要使用二分搜索或者是分治法解决。
 * 
 * 设 nums1 = [1, 3, 5, 7, 9], nums2 = [0, 2, 4, 6, 8, 10, 12, 14]
 * 
 * => 融合后的列表: nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14]
 * 
 * (nums1.size() + nums2.size()) / 2 = 13 / 2 = 6，所以我们要做的事情就是找到融合数组的第 6 个元素，也就是 nums[6]。
 * 
 */
class Solution {
private:
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];

        if (j >= nums2.size()) return nums1[i + k - 1];
        
        if (k == 1) return min(nums1[i], nums2[j]);

        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
};