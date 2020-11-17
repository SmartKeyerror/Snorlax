
#include <vector>

using namespace std;

/*
 * Longest Increasing Subsequence， 简称为 LIS
 * LIS(i) 表示第 i 个元素所组成的最长上升子序列，那么 LIS(i) = max { LIS(k) + 1， LIS(p) + 1, ...}，其中 nums[k]、nums[p] 均小于 nums[i]  (数学没学好，不知道怎么更抽象的表示...)
 * 
 * 我们以 nums = [10,9,2,5,3,7,101,18] 为例，将 LIS(i) 初始化为 1,这是因为每一个元素都是长度为 1 的 LIS
 * 
 * - 对于元素 9，前面没有小于它的元素，所以 LIS(1) = max(0, LIS(1))，结果为 1，元素 2 同理，故 LIS(2) = 1
 * - 对于元素 5，也就是索引为 3 的元素， 前面有小于它的元素(元素 2)，所以 LIS(3) = max(LIS(2)+1, LIS(3))，LIS(3) = 2
 * - 对于元素 3, 同元素 2,所以 LIS(4) = 2
 * - 对于元素 7, 前面有多个小于它的元素，所以 LIS(5) = max(LIS(2)+1, LIS(3)+1, LIS(4)+1, LIS(5)), LIS(5) = 3
 * - 对于元素 101, LIS(6) = max(LIS(0)+1, LIS(1)+1, LIS(2)+1, LIS(3)+1, LIS(4)+1, LIS(5)+1, LIS(6))，LIS(6) = 4
 * - 对于元素 18, LIS(7) = max(LIS(0)+1, LIS(1)+1, LIS(2)+1, LIS(3)+1, LIS(4)+1, LIS(5)+1, LIS(7))，LIS(7) = 4
 * 
 * leetcode 上 “牲口” 还是多啊，O(nlogn) 的算法都有...respect, respect
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> lis(nums.size(), 1);

        int result = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                    result = max(result, lis[i]);
                }
            }
        }
        return result;
    }
};
