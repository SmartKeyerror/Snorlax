
#include <vector>

using namespace std;


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();

        vector<bool> result(n, false);

        int current = 0;

        for (int i = 0; i < n; i++) {
            current = (current * 2 + nums[i]) % 5;
            result[i] = current == 0;
        }

        return result;
    }
};
