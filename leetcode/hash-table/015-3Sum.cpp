
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * 因为有重复元素，所以使用 map or set 的效果不是很理想，所以使用滑动窗口解决
 * 思路如下: 我们要找 a + b + c = 0，也就是 a = -(b+c)，那么我们逐一地固定数组中的每一个元素，在其后面的子数组中找两个数之和为 -fixed 即可
 * 在遍历数组寻找 finxed 时，我们需要跳过重复元素，因为我们不应该固定同一个元素两次。滑动窗口中的指针同理，也应该跳过重复元素
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        if (nums.empty() || nums.back() < 0 || nums.front() > 0 || nums.size() < 3)
            return {};

        // 只需要 fixed 倒数第3个元素即可，得留出滑动窗口中 j、k 指针的舞台
        for (int i = 0; i <= nums.size()-3; i++) {

            if (nums[i] > 0)        // 如果 fixed 是一个正数的，后续的值 >= fixed，不可能凑成 0
                break;

            if (i > 0 && nums[i] == nums[i-1])      // 过滤重复元素
                continue;

            int target = 0 - nums[i];
            int j = i + 1, k = nums.size()-1;

            // 滑动窗口
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++, k--;
                }
                else if (nums[j] + nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};
