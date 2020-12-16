
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * 求数组中乘积最大的三个数， 因为不要求连续，所以我们可以试着从逻辑上去思考这个问题。
 * 
 * 如果 nums 全部大于 0 或者全部小于 0 的话，那么最大乘积就是排序后的后的最后三个数
 * 在有正有负的情况下，就需要进行比较了。两个最小的负数 * 最大的正数，或者是三个正数相乘
 * 
 * 我还是不知道这题用 Hashmap 该怎么做
 */
class Solution {
private:
    int sortSloution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        if (nums.front() >= 0 || nums.back() <= 0)
            return last;
        else
            return max(nums[0]*nums[1]*nums.back(), last);
    }
public:
    int maximumProduct(vector<int>& nums) {
        return sortSloution(nums);
    }
};
