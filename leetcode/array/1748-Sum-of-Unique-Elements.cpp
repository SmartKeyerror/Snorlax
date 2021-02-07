#include <vector>
#include <unordered_map>

using namespace std;

// 还有这么简单的问题?
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) freq[nums[i]] ++;

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] == 1) res += nums[i];
        }
        return res;
    }
};