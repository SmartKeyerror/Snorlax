
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int piovt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i+1] < nums[i]) {
                piovt = i;
                break;
            }
        }
        return min(nums[0], nums[piovt+1]);
    }
};
