
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int invalidPos = -1, n = nums.size();

        for (int i = 1; i < n; i++) {

            if (nums[i] < nums[i-1]) {

                if (invalidPos != -1) return false;

                invalidPos = i;

                if (i == n - 1 || i == 1) continue;

                else if (nums[i] < nums[i-2] && nums[i+1] < nums[i-1]) return false;
            }    
        }
        return true;
    }
};
