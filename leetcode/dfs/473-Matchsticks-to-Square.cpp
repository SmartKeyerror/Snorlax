
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


class Solution {
public:

    bool dfs(vector<int>& nums, int shards, int index,int a, int b, int c, int d) {
        if (index >= nums.size()) {
            if (a == b && c == d && a == c) return true;
            return false;
        }

        if (a + nums[index] <= shards && dfs(nums, shards, index + 1, a + nums[index], b, c, d))
            return true;

        if (b + nums[index] <= shards && dfs(nums, shards, index + 1, a, b + nums[index], c, d))
            return true;
        
        if (c + nums[index] <= shards && dfs(nums, shards, index + 1, a, b, c + nums[index], d))
            return true;
        
        if (d + nums[index] <= shards && dfs(nums, shards, index + 1, a, b, c, d + nums[index]))
            return true;
        
        return false;
    }

    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum == 0 || sum % 4 != 0) return false;

        int shards = sum / 4;

        // Question: 为什么 nums 从大到小排列就不会 TLE 呢?
        sort(nums.rbegin(), nums.rend());

        return dfs(nums, shards, 0, 0, 0, 0, 0);
    }
};