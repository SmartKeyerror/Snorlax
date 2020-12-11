

#include <vector>
#include <algorithm>

using namespace std;


/*
 * 一道找规律的问题
 * 
 * [1,4,3,2,6,5] 的下一个排列是 [1,4,3,5,2,6]
 * [1,6,2,3,5,4] 的下一个排列是 [1,6,2,4,3,5]
 * [6,5,4,3,2,1] 的下一个排列是 [1,2,3,4,5,6]
 * 
 * 对于 1, 4, 3, 2, 6, 5 而言，从后向前看，数字逐渐增大，直到 2 停止，然后再从后往前找比 2 大的第一个数字，结果为 5, 交换 2 和 5 的位置，变成 [1,4,3,5,6,2]
 * 然后 reverse 5 以后的元素，也就是 [1,4,3,5,2,6]
 * 
 * 这特喵的是哪个鬼才想出来的，respect, respect。
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i+1] > nums[i]) {
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
