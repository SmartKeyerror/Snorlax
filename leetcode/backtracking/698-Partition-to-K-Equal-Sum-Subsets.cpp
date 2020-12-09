
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

/*
 * 这道题虽然归在了 DP 的 Topic 之下，但是我觉得用回溯+剪枝的方式来做更好
 */
class Solution {
    vector<bool> used;
    bool backtracking(vector<int>& nums, int k, int index, int sum, int &target) {
        if (k == 1) return true;

        if (sum > target) return false;

        if (sum == target)
            return backtracking(nums, k - 1, 0, 0, target);
        
        for (int i = index; i < nums.size(); i++) {
            if (used[i]) continue;
            
            // 进行选择
            used[i] = true;

            if (backtracking(nums, k, i + 1, sum + nums[i], target))
                return true;

            used[i] = false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        used = vector<bool>(nums.size(), false);

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;
        int target = sum / k;

        // 这里我们需要从大到小排列，否则会超时
        sort(nums.begin(), nums.end(), greater<int>());     

        return backtracking(nums, k, 0, 0, target);
    }
};


#include <iostream>
#include <time.h>
int main() {
    int k = 13;
    vector<int> nums = {4,5,3,2,5,5,5,1,5,5,5,5,3,5,5,2};

    clock_t start = clock();

    cout << Solution().canPartitionKSubsets(nums, k) << endl;

    cout << (clock() - start) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;
}
