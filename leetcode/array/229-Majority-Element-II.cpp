
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nbr1 = 0, nbr2 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nbr1) count1 ++;
            else if (nums[i] == nbr2) count2 ++;
            else if (count1 == 0) nbr1 = nums[i], count1 ++;
            else if (count2 == 0) nbr2 = nums[i], count2 ++;
            else count1 --, count2 --;
        }

        // 对 nbr1、nbr2 重新进行计数
        count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nbr1) count1 ++;
            else if (nums[i] == nbr2) count2 ++;
        }

        vector<int> res;
        if (count1 > (nums.size() / 3)) res.push_back(nbr1);
        if (count2 > (nums.size() / 3)) res.push_back(nbr2);
        return res;
    }
};