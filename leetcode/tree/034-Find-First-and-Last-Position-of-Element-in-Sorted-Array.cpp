
#include <vector>

using namespace std;

/*
 * 在有序列表中寻找某一个元素的起始和结束索引。二分查找没跑了
 * 
 * 二分查找只能找到这个值是不是在列表中，但是不能确定其位置，所以我们需要对二分查找进行改装
 * 
 * 代码可以分成两部分，一部分寻找起始点，另一部分寻找结束点。
 * 
 */
class Solution {
public:
    int findLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target || nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        if (left > nums.size() - 1 || nums[left] != target) return -1;
        return left;
    }

    int findRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target || nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        if (right < 0 || nums[right] != target) return -1;
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        return {findLeft(nums, target), findRight(nums, target)};
    }
};

#include <iostream>
int main() {
    // vector<int> nums = {6, 7, 8, 8, 8, 8, 8, 8, 9};
    vector<int> nums = {2, 2};
    printf("left: %d \n", Solution().findLeft(nums, 3));
    printf("right: %d \n", Solution().findRight(nums, 3));
    Solution().searchRange(nums, 2);
}
