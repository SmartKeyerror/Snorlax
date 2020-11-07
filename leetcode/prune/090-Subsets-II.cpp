
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;


class Solution {
    vector<bool> used;
    vector<vector<int>> result;

    void generateSubsets(vector<int>& nums, int index, vector<int> &selected) {

        if (selected.size() != 0) {
            result.push_back(selected);
        }

        for (int i = index; i < nums.size(); i++) {
            if (used[i])
                continue;
            
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
            
            selected.push_back(nums[i]);
            used[i] = true;

            generateSubsets(nums, i + 1, selected);

            used[i] = false;
            selected.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();

        if (nums.size() == 0)
            return result;

        used = vector<bool>(nums.size(), false);
        
        vector<int> selected;

        sort(nums.begin(), nums.end());

        result.push_back(vector<int> {});
        generateSubsets(nums, 0, selected);

        return result;
    }
};
