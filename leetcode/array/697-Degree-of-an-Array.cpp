
#include <vector>
#include <unordered_map>
#include <climits>


using namespace std;


/*
 * 求 nums 数组中包含所有出现频次最高的最短连续子数组的长度。例如 [1, 2, 2, 3, 3, 3, 2, 4, 1]，出现频次最高的为 2 或 3，而包含 2 或者 3 的最短连续子数组为 [3, 3, 3]，所以结果为 3。
 * 
 * 在遍历的过程中我们不仅要记录出现频次最高的数字，同时也需要记录该数字起始和结束的索引，便于后面计算连续子数组的长度。
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> freq;

        int maxFreq = 0;
        vector<int> candidates;

        for (int i = 0; i < n; i++) {
            if (freq.count(nums[i])) {
                freq[nums[i]][1] = i;
                freq[nums[i]][2] ++;
            } else
                freq.insert({nums[i], {i, i, 1}});
            
            if (freq[nums[i]][2] > maxFreq) {
                candidates.clear();
                candidates.push_back(nums[i]);
                maxFreq = freq[nums[i]][2];
            }
            else if (freq[nums[i]][2] == maxFreq)
                candidates.push_back(nums[i]);
        }

        int result = INT_MAX;
        for (int i = 0; i < candidates.size(); i++) {
            int length = freq[candidates[i]][1] -  freq[candidates[i]][0] + 1;
            result = min(result, length);
        }

        return result;
    }
};


/*
 * 给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
 * 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 输入：[1, 2, 2, 3, 1]
 * 输出：2
 * 解释：输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 题目需要求最短连续子数组，并且统计的是窗口内元素出现的频率，具有单调性，所以可以使用滑动窗口解决。
 * 
 * 相似问题: 
 * - 76. Minimum Window Substring
 */

class Solution {
private:

    // 获取 nums 数组的度，时空复杂度均为 O(N)
    int getDegreeOfNums(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const auto num : nums) freq[num] ++;
        int res = 1;
        for (const auto& item : freq) {
            res = max(res, item.second);
        }
        return res;
    }

public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = getDegreeOfNums(nums);

        // 我们该使用哪种数据结构来维护窗口，从而在 O(1) 时间内判断当前窗口是否满足题目要求?

        int left = 0;
        int result = nums.size();

        unordered_map<int, int> window;

        for (int right = 0; right < nums.size(); right++) {
            window[nums[right]] ++;

            // 若当前窗口满足条件，则主动缩小窗口
            while (window[nums[right]] == degree) {
                result = min(result, right - left + 1);
                
                window[nums[left]] --;

                if (window[nums[left]] == 0) 
                    window.erase(nums[left]);
                
                left ++;
            }
        }

        return result;
    }
};