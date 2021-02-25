
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), duplicated = 0, missing = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) freq[nums[i]]++;

        for (int i = 1; i <= n; i++) {
            if (freq.count(i) == 0) missing = i;
            else if (freq[i] == 2) duplicated = i;
            else freq[i] ++;
        }
        return {duplicated, missing};
    }
};