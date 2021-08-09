
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int left = 0, right = n - 1;
        int mid;

        while (left <= right) {
        
            mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // 此时 [left, mid] 是有序的，比如说 [3, 4, 5, 6, 1, 2, 3]
            if (nums[mid] >= nums[left]) {
                // 此时讨论 target 就在 [left, mid] 一有序的区间内
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // 此时说明 [mid, right] 是有序的，比如说 [5, 6, 1, 2, 3, 4]
            else {
                // 此时讨论 target 就在 [mid, right] 这一有序的区间内
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;

    }
};
