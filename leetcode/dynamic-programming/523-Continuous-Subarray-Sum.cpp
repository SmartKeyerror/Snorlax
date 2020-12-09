#include <vector>

using namespace std;

class Solution {
private:
    bool brouteSolution(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                // MD k 还有可能为 0
                if (sum == k) return true;
                if (k != 0 && sum % k == 0) return true;
            }
        }
        return false;
    }
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        return brouteSolution(nums, k);
    }
};
