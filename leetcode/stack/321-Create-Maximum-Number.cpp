
#include <vector>

using namespace std;

/*
 * You are given two integer arrays nums1 and nums2 of lengths m and n respectively. 
 * nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
 * 
 * Create the maximum number of length k <= m + n from digits of the two numbers. 
 * The relative order of the digits from the same array must be preserved.
 * 
 * Return an array of the k digits representing the answer.
 * 
 * 相似题目:
 * - 给定一个正整数数组和 k，要求依次取出 k 个数，输出其中数组的一个子序列，需要满足：1. 长度为 k；2.字典序最大。
 * - 10 亿个数求 Top-K 问题。
 * 
 * 首先，给定一个数组，然后让我们取 K 个数，并且维持原有元素顺序的话，不管是结果是最大还是最小，都是用单调栈来完成。
 * 
 * 但是，这道题目给了 2 个数组，让我们在这两个数组中一共取 K 个数，使得结果最大。
 * 
 * 我们可以借鉴 “10 亿个数求 Top-K 问题” 中的分治思想，在 nums1 和 nums2 中分别取 1, 2, 3, 4, ... k-i 个数，这 K 个数就是当前数组最大的。
 * 
 * 例如 nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3]，K = 2。
 * 
 * nums1 中可以取 0 个数，取 1 个数，取 2 个数 : [], [6], [6, 5]
 * nums2 中可以取 2 个数，取 1 个数，取 0 个数 : [9, 8], [9], []
 *
 * 然后我们再用类似于归并排序的方式对其进行归并即可，注意这里的归并必须使用完成的数组进行比较。
 */

class Solution {
private:
    // 在 nums 数组中寻找字典序最大的 k 个数的子序列，不足 k 个的话直接返回 nums
    vector<int> findMaxSeq(const vector<int>& nums, int k) {        

        int n = nums.size(), removed = n - k;

        // 这里使用 vector 来模拟栈，减少不必要的结果处理
        vector<int> st;

        for (int i = 0; i < n; i++) {
            int current = nums[i];
            
            while (!st.empty() && current > st.back() && removed > 0) {
                removed--;
                st.pop_back();
            }

            st.push_back(current);
        }

        while (removed) {
            st.pop_back();
            removed--;
        }

        return st;
    }

    // 合并两个序列
    vector<int> merge(vector<int>& A, vector<int>& B) {
        vector<int> result;

        while (!A.empty() || !B.empty()) {
            if (A > B) {
                result.push_back(A[0]);
                A.erase(A.begin());
            } else {
                result.push_back(B[0]);
                B.erase(B.begin());
            }
        }
        return result;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> result(k, 0);

        for (int i = 0; i <= k; i++) {
            int k1 = i, k2 = k - i;
            if (k1 <= nums1.size() && k2 <= nums2.size()) {
                auto s1 = findMaxSeq(nums1, k1), s2 = findMaxSeq(nums2, k2);
                result = max(result, merge(s1, s2));
            }
        }
        return result;
    }
};