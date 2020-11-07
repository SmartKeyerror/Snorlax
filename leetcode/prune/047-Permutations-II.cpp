
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;


class Solution {
private:
    vector<bool> used;
    vector<vector<int>> result;

    void permute(vector<int>& nums, vector<int> &selected) {

        if (selected.size() == nums.size()) {
            result.push_back(selected);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            
            if (i > 0 && nums[i] == nums[i - 1] && !used[i-1])
                continue;
            
            used[i] = true;
            selected.push_back(nums[i]);

            permute(nums, selected);

            selected.pop_back();
            used[i] = false;
        }

        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();

        if (nums.size() == 0)
            return result;

        used = vector<bool>(nums.size(), false);
        
        vector<int> selected;
        sort(nums.begin(), nums.end());
        permute(nums, selected);

        return result;
    }
};
