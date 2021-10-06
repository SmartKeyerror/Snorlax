
#include <vector>

using namespace std;


/*
 * 给定一个大小为 n 的 整形数组，其元素大小在 [1, n] 区间内，并且每一个数字要么出现一次
 * 要么出现两次，找出所有出现两次的数字。要求时间复杂度为 O(n) 和空间复杂度为 O(1)。
 * 
 * 例: 
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [2,3]
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i < n;i++) {
            int num = abs(nums[i]);

            if (nums[num-1] < 0) 
                res.push_back(num);
            else nums[num-1] *= -1;
        }
        
        return res;
    }
};
