
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 限制条件: candidates 中元素不重复，但可以重复选取， 目标 target 最多包含 150 个元素
 * 下面采用纯粹的 回溯法 结果，无减枝
 */
class Solution {
private:
    vector<vector<int>> result;

    // 在 candidates[index...size()-1] 中选择和为 target 的一个或者多个数
    void generateCombination(vector<int> &candidates, int target, int index, vector<int> &selected, int selected_target) {
        if (selected_target > target)
            return;
        
        if (selected.size() > 150)
            return;

        if (selected_target == target) {
            result.push_back(selected);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            selected.push_back(candidates[i]);
            selected_target += candidates[i];
            generateCombination(candidates, target, i, selected, selected_target);
            selected_target -= candidates[i];
            selected.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> selected;

        generateCombination(candidates, target, 0, selected, 0);
        
        return result;
    }
};