
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


class Solution {
private:
    // 看看暴力解法是什么样儿的
    // Runtime: 16 ms, faster than 28.00% of C++ online submissions for Maximum Gap.
    int sortSolution(vector<int>& nums) {
        int maximum = 0;
        if (nums.size() < 2) return maximum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            maximum = max(maximum, nums[i+1] - nums[i]);
        return maximum;
    }

public:
    int maximumGap(vector<int>& nums) {
        return sortSolution(nums);
    }
};
