
#include <vector>
#include <queue>

using namespace std;

/*
 * 给你一个整数数组 nums ，你的目标是令 nums 中的所有元素相等。完成一次减少操作需要遵照下面的几个步骤：
 * 
 * 1. 找出 nums 中的最大值。记这个值为 largest 并取其下标 i （下标从 0 开始计数）。如果有多个元素都是最大值，则取最小的 i 。
 * 2. 找出 nums 中的 下一个最大 值，这个值严格小于 largest ，记为 nextLargest 。
 * 3. 将 nums[i] 减少到 nextLargest 。
 * 
 * 返回使 nums 中的所有元素相等的操作次数。
 * 
 * 输入：nums = [5,1,3]
 * 输出：3
 * 解释：需要 3 次操作使 nums 中的所有元素相等：
 * 1. largest = 5 下标为 0 。nextLargest = 3 。将 nums[0] 减少到 3 。nums = [3,1,3] 。
 * 2. largest = 3 下标为 0 。nextLargest = 1 。将 nums[0] 减少到 1 。nums = [1,1,3] 。
 * 3. largest = 3 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [1,1,1] 。
 * 
 * 优先队列的一个典型使用 ，按部就班的执行题目要求的操作即可。
 * 
 * 一个问题，有多个 largest 时，随机选取一个 i 会有问题吗? 不会
 * 
 * 优先队列的实现超时，想岔了，排序后直接遍历即可
 */

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int count = 0;

        priority_queue<int> pool;

        for (int i = 0; i < nums.size(); i++) pool.push(nums[i]);

        vector<int> temp;

        while (true) {
            int current = pool.top();
            pool.pop();

            while (!pool.empty() && pool.top() == current) {
                temp.push_back(pool.top());
                pool.pop();
            }

            // 终止条件
            if (pool.empty()) break;

            int next = pool.top();
            pool.pop();

            // 重新推入
            pool.push(next);
            pool.push(next);

            for (int i = 0; i < temp.size(); i++) pool.push(temp[i]);

            temp.clear();

            count ++;
        }

        return count;
    }
};


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0, n = nums.size();

        for (int i = 0; i < n - 1;i++) {
            if (nums[i+1] > nums[i])
                count += n - i - 1;
        }

        return count;
    }
};