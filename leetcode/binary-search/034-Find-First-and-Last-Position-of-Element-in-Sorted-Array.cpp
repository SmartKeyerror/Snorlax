
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
private:
    int findFirstIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 相等的情况我们需要判断 mid 是否就是第一个出现的位置
            if (nums[mid] == target) {
                // mid 是第一个元素，或者是 mid 的前一个元素不等于 mid
                if (mid == 0 || nums[mid-1] != nums[mid]) return mid;
                // 此时 mid 一定不是第一个位置，所以我们向左继续搜索
                else right = mid - 1;
            }
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

    int findLastIndex(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 相等的情况我们需要判断 mid 是否就是最后一个出现的位置
            if (nums[mid] == target) {
                // mid 是最后一个元素，或者是 mid 的下一个元素不等于 mid
                if (mid == nums.size() - 1 || nums[mid+1] != nums[mid]) return mid;
                // 此时 mid 一定不是最后一个位置，所以我们向右继续搜索
                else left = mid + 1;
            }

            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstIndex(nums, target);
        int last = findLastIndex(nums, target);
        return {first, last};
    }
};
