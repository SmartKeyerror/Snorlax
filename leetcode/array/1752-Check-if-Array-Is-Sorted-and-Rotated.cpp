

#include <vector>

using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int position = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                position = i + 1;
                break;
            }
        }

        if (position == -1) return true;

        for (int i = position; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) return false;
            if (nums[i] > nums[0]) return false;
        }
        return true;
    }
};