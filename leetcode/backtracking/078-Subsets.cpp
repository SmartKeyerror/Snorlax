
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;

    void generateSubsets(vector<int>& nums, int index, vector<int> &selected) {

        // 每次的选择路径都需要丢到 result 中
        if (selected.size() != 0)
            result.push_back(selected);
        
        for (int i = index; i < nums.size(); i++) {
            selected.push_back(nums[i]);
            generateSubsets(nums, i + 1, selected);
            selected.pop_back();   
        }

        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        result.clear();

        if (nums.size() == 0)
            return result;
        
        result.push_back(vector<int> {});

        vector<int> selected;
        generateSubsets(nums, 0, selected);

        return result;
    }
};
