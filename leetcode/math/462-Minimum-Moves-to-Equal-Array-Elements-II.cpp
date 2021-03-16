
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 给定 nums 数组，问将 nums 中的元素 move 成相同元素所需要的最小代价。
 * 
 * 将 nums 排序后找到其中位数即可，左、右两边的元素均向其靠拢，便是最小代价。
 */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() / 2, result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result += abs(nums[i] - nums[mid]);
        }
        return result;
    }
};