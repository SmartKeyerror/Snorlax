
#include <vector>
#include <numeric>

using namespace std;

/*
 * 计算 nums 数组中每一个小于 nums[i] 的个数。
 */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> frequency(101, 0);

        for (int num : nums) frequency[num] ++;

        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            result[i] = accumulate(frequency.begin(), frequency.begin() + nums[i], 0);
        }

        return result;
    }
};
