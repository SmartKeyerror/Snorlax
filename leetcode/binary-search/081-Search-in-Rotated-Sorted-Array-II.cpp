
#include <vector>

using namespace std;

/*
 * 一道 Ctrl+C/V 的问题，把 33.Search in Rotated Sorted Array 问题的答案稍加修改即可
 */
class Solution {
private:
    bool binarySearch(vector<int>& nums, int left, int right, int &target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {

        if (nums.size() == 0) return false;

        int piovt;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i+1] < nums[i]) {
                piovt = i;
                break;
            }
        }

        if (nums[piovt] == target) return true;
        int left = binarySearch(nums, 0, piovt - 1, target);
        int right = binarySearch(nums, piovt + 1, nums.size() - 1 , target);
        return left || right;
    }
};