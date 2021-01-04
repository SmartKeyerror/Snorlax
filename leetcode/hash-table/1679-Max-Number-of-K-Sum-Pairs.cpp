
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * two sum 问题的进阶版
 */
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int answer = 0;
        unordered_map<int, int> record;

        for (int i = 0; i < nums.size(); i++) {
            if (record.count(k - nums[i])) {
                record[k - nums[i]] --;
                if (record[k - nums[i]] <= 0) record.erase(k - nums[i]);
                answer ++;
            } else
                record[nums[i]] ++;
        }
        return answer;
    }
};