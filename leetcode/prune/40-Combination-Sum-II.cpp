

#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;

/*
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 */
class Solution {
private:
    vector<vector<int>> result;
    vector<bool> used;

    void generateCombination(vector<int>& candidates, int target, int index, vector<int> &selected, int selected_target) {

        if (selected_target == target) {
            result.push_back(selected);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // 若当前选择路径已经被使用，剪枝
            if (used[i])
                continue;

            // 若当前选择的 num 比 target 还要大的话，那么当前 candidates[i] 以及其后面所有的路径均可被剪枝
            if (candidates[i] > target)
                break;

            // 同样的，如果 (当前选择路径 + 已选择路径和) > target 的话，也可以剪枝
            if (candidates[i] + selected_target > target)
                break;
            
            // 和 Permutations-II 问题一样，我们需要考虑重复元素，剪枝条件是一样的
            if (i > 0 && candidates[i] == candidates[i-1] && !used[i-1])
                continue;
            
            selected_target += candidates[i];
            selected.push_back(candidates[i]);
            used[i] = true;

            generateCombination(candidates, target, i + 1, selected, selected_target);

            used[i] = false;
            selected.pop_back();
            selected_target -= candidates[i];
        }

        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        result.clear();

        if (candidates.size() == 0)
            return result;

        vector<int> selected;

        used = vector<bool>(candidates.size(), false);

        sort(candidates.begin(), candidates.end());

        generateCombination(candidates, target, 0, selected, 0);

        return result;
    }
};
