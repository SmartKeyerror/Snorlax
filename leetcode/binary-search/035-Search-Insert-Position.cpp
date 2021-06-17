

#include <vector>

using namespace std;


// 35. Search Insert Position，要么找到 target，要么找到 target 应该插入的位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
        }

        // 返回 left 还是 right? 
        // nums = [1,3,5,6], target = 7，最终 left 为 4， right 为 3，应该插入至 left 位置
        return left;
    }
};