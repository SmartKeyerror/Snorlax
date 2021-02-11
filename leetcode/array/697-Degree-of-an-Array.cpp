
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