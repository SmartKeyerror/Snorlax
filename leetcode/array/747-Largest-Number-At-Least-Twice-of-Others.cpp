
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_value = *max_element(nums.begin(), nums.end()); 
        int index;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == max_value) index = i;
            if(nums[i] * 2 > max_value && nums[i] != max_value)return -1;
        }
        return index;
    }
};