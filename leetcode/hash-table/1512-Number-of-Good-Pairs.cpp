
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 给定 nums 数组，返回 nums[i] == nums[j] and i < j 全部 i,j 组合数量
 */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.count(nums[i])) result += record[nums[i]];
            record[nums[i]] ++;
        }
        return result;
    }
};