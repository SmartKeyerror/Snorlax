
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 限制条件: candidates 中元素不重复，但可以重复选取， 目标 target 最多包含 150 个元素
 * candidates = [2,3,6,7], target = 7
 * 
 * 现在来看减枝的情况, 其实减枝起来非常简单，只需要对 candidates 进行一次排序即可
 * 当递归到 candidates[index] > target 时，index 后的所有路径均可不必遍历
 * 
 * Runtime: 8 ms, faster than 89.32% of C++ online submissions for Combination Sum.
 */
class Solution {
private:
    vector<vector<int>> result;

    // 在 candidates[index...size()-1] 中选择和为 target 的一个或者多个数
    void generateCombination(vector<int> &candidates, int target, int index, vector<int> &selected, int selected_target) {
        if (selected.size() > 150)
            return;

        if (selected_target == target) {
            result.push_back(selected);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            
            if (candidates[i] > target || selected_target + candidates[i] > target) break;

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

        sort(candidates.begin(), candidates.end());
        generateCombination(candidates, target, 0, selected, 0);
        
        return result;
    }
};