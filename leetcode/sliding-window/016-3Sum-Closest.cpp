
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

/*
 * 3Sum 问题的另一个版本，要求找到 3 个数的和最接近 target，并返回这个和
 * 
 * 老规矩，先排序，然后用 Sliding Window 的方式解决
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int result = (target > 0 ? INT_MAX - target: INT_MAX + target);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == target)
                    return target;
            
                else if (nums[i] + nums[left] + nums[right] < target) {
                    if (abs(target - nums[i] - nums[left] - nums[right]) < abs(target - result))
                        result = nums[i] + nums[left] + nums[right];
                    left ++;
                } 
                
                else {
                    if (abs(target - nums[i] - nums[left] - nums[right]) < abs(target - result))
                        result = nums[i] + nums[left] + nums[right];
                    right --;
                }
            }
        }
        return result;
    }
};
