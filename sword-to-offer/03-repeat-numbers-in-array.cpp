

/*
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 * 
 * 三种方式: 
 * - 使用 hashset，时间复杂度 O(n)，空间复杂度 O(n)
 * - 排序+prev、cur 指针，时间复杂度 O(nlogn)，空间复杂度 O(1)
 * - 因为 nums 数组中元素大小在 0 ~ n-1，所以我们可以使用置换的方式来完成。也就是将值为 X 的元素放到索引 X 上。时间复杂度 O(n)，空间复杂度 O(1)
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    int hashsetSolution(vector<int>& nums) {
        unordered_set<int> pool;
        for (int i = 0; i < nums.size(); i++) {
            if (pool.count(nums[i]) != 0) return nums[i];
            pool.insert(nums[i]);
        }
        return -1;
    }

    int sortSolution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int cur = 1; cur < nums.size(); cur ++) {
            if (nums[cur] == nums[cur - 1]) return nums[cur];
        }
        return -1;
    }

    int swapSolution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            if (current == i) continue;
            else if (nums[current] == nums[i]) return current;
            else swap(nums[i], nums[current]);
        }
        return -1;
    }
public:
    int findRepeatNumber(vector<int>& nums) {
        return hashsetSolution(nums);
        return sortSolution(nums);
        return swapSolution(nums);
    }
};