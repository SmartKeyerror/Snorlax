
#include <vector>

using namespace std;

/*
 * Moving Zeroes 的变种，将 zero 换成了 value 而已
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nextPosi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[nextPosi] = nums[i];
                nextPosi++;
            }
        }
        return nextPosi + 1;
    }
};