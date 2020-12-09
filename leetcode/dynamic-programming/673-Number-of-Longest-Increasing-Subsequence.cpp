
#include <vector>
#include <limits.h>

using namespace std;

/*
 * LIS 问题，不再问最长上升子序列是多长，而是问最长上升子序列有多少个
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int longest = 1;

        vector<int> memory(nums.size() + 1, 1);
        vector<int> count(nums.size() + 1, 1);

        for (int i = 1; i < nums.size(); i++) {
            int current = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && memory[j] >= current) {
                    if (memory[j] == current)
                        count[i] += count[j];
                    else
                        count[i] = count[j];
                    current = memory[j];
                }
            }
            memory[i] = current + 1;
            longest = max(memory[i], longest);
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (memory[i] == longest)
                res += count[i];
        }
        return res;
    }
};
