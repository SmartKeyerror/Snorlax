
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * 如果按照 3Sum 的思路来看的话，4Sum 就是在 fix 一个数值以后， 在剩下的子数组中寻找 3Sum，这样一来，时间复杂度为 O(n^3)
 * 题目中给出了 0 <= nums.length <= 200， 200^3 在 8000000 这个数量级上，要比 3Sum 中 3000^2 还要小一些，所以时间上是可以接受的
 * 
 * a + b + c + d = target
 * 
 * 除了下面给出的答案以外，还有一些看起来非常不错的方法:
 * - https://leetcode.com/problems/4sum/discuss/737096/Sum-MegaPost-Python3-Solution-with-a-detailed-explanation
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        if (nums.empty() || nums.size() < 4)
            return {};

        for (int i = 0; i <= nums.size() - 4; i++) {

            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j <= nums.size() - 3; j++) {

                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                int left = j + 1, right = nums.size() - 1;

                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) left ++;
                        while (left < right && nums[right] == nums[right-1]) right --;
                        left ++, right --;
                    } else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left ++;
                    else
                        right --;
                }
            }
        }
        return result;
    }
};
