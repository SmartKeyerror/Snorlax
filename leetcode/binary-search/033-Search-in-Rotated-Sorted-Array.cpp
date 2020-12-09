
#include <vector>

using namespace std;

/*
 * 在一个被 rotate 的有序列表中查找某一个元素，例如原有有序列表为: [0,1,2,4,5,6,7], rotate 之后结果为 [4,5,6,7,0,1,2]
 * 
 * 一个比较简单的作法就是先找到 pivot 的位置，判断 nums[pivot] 和 target 之间的大小关系:
 * - 若 target > nums[pivot]，问题无解
 * - 若 target < nums[pivot], 那么我们此时需要在列表的左、右两侧分别进行二分查找
 *   即对 nums[0...pivot-1] 以及 nums[piovt+1...nums.szie()-1] 进行二分查找
 * 
 * 另外的方式就是直接进行二分查找
 */
class Solution {
private:
    int binarySearch(vector<int>& nums, int left, int right, int &target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

    int intuitiveSolution(vector<int>& nums, int target) {
        // 题目告诉我们了 piovt 一定存在，所以就不用对 piovt 进行判断了。
        int piovt;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i+1] < nums[i]) {
                piovt = i;
                break;
            }
        }

        if (nums[piovt] == target) return piovt;
        int left = binarySearch(nums, 0, piovt - 1, target);
        int right = binarySearch(nums, piovt + 1, nums.size() - 1 , target);

        if (left < 0 && right < 0) return -1;
        return left > right ? left: right;
    }

public:
    int search(vector<int>& nums, int target) {
        // O(n)
        return intuitiveSolution(nums, target);
    }
};
