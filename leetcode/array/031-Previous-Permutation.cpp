
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * leetcode 中并没有这道题目，由 Next Permutation 问题衍生而来，求上一个排列
 */
class Solution {
public:
    void previousPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i+1] < nums[i]) {
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] < nums[i]){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums = {1, 4, 1, 2, 5, 6};
    Solution().previousPermutation(nums);
    for (int num : nums)
        cout<<num<<", ";
    cout<<endl;
}
