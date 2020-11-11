
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        int next = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[next]) {
                next++;
                nums[next] = nums[i];
            }
        }

        return next + 1;
    }
};