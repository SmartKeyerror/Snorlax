
#include <vector>

using namespace std;


// 二分查找问题
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == nums[mid]) return mid;

            if (target > nums[mid]) left = mid + 1;

            else right = mid - 1;
        }
        return left;
    }
};