

#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;


/*
 * 在 [1..9] 中选择 k 个数，使得其总和为 n，每个数仅能选择一次，并且为组合问题，而非排列
 * 2 <= k <= 9
 * 1 <= n <= 60
 */
class Solution {
    
    vector<bool> used;
    vector<vector<int>> result;

    void generateCombinations(int k, int n, int index, vector<int> &selected, int selected_target) {
        if (selected.size() == k && selected_target == n) {
            result.push_back(selected);
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (used[i])
                continue;
            
            // 剪枝条件: 当前选择路径比目标和还要大
            if (i > n)
                break;
            
            // 剪枝条件: 当前路径和比目标和还要大
            if (i + selected_target > n)
                break;
            
            selected.push_back(i);
            selected_target += i;
            used[i] = true;

            generateCombinations(k, n, i + 1, selected, selected_target);

            used[i] = false;
            selected_target -= i;
            selected.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();

        used = vector<bool>(9, false);

        vector<int> selected;
        generateCombinations(k, n, 1, selected, 0);

        return result;
    }
};