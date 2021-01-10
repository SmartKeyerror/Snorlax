
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 求一个未排序的、带有重复元素的 nums 数组中的最长连续子序列，连续子序列指 [1,2,3,4,..] 这样的连续实数。
 * 
 * Solution A: 对 nums 进行排序，从第 0 个元素开始寻找连续的子数组，下次寻找时需要从 起始点 + 上一次找到的子数组长度 开始。
 */
class Solution {
private:
    int sortSolution(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        int maxSize = 1, preSize = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 1) 
                preSize ++;
            else if (nums[i] == nums[i-1])
                continue;
            else
                preSize = 1;
            maxSize = max(maxSize, preSize);
        }
        return maxSize;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        return sortSolution(nums);
    }
};