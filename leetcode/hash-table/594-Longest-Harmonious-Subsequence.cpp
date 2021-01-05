
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;

/*
 * 求 nums 数组中最长的一个子序列，这个子序列要求序列中的最大元素和最小元素之间的绝对值为 1。
 * 
 * 因为最大值和最小值之间的绝对值不能超过 1 ，那么若想要子序列长度大于 2 的话，必然存在重复，例如 [1, 1, 2] 或者 [1, 2, 2]，因此我们可以做频次统计。
 * 
 * 在统计完每个 num 出现的频次以后，遍历一遍 frequency 字典，每一个 key + 1 或者 key - 1 进行查找、相加、比较即可
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num] ++;
        
        int res = 0;
        for (auto item : freq) {
            if (freq.count(item.first + 1)) 
                res = max(res, item.second + freq[item.first + 1]);
            if (freq.count(item.first - 1)) 
                res = max(res, item.second + freq[item.first - 1]);
        }
        return res;
    }
};