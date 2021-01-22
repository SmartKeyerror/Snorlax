
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 * 
 * No，I can't. [狗头]
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> frequency;

        for (int num : nums) frequency[num] ++;
        for (int num : nums) {
            if (frequency[num] == 1) res.push_back(num);
        }
        return res;
    }
};
