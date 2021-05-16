
#include <vector>

using namespace std;


class Solution {
private:

    vector<vector<int>> subsets;

    void generateSubsets(vector<int>& nums, int index, vector<int> &selected) {

        // 每次的选择路径都需要丢到 result 中
        if (selected.size() != 0)
            subsets.push_back(selected);
        
        for (int i = index; i < nums.size(); i++) {
            selected.push_back(nums[i]);
            generateSubsets(nums, i + 1, selected);
            selected.pop_back();   
        }

        return;
    }
public:

    int subsetXORSum(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> selected;
        generateSubsets(nums, 0, selected);

        int result = 0;

        for (auto subset : subsets) {
            int current = subset[0];
            for (int i = 1; i < subset.size(); i++) {
                current = current ^ subset[i];
            }
            result += current;
        }

        return result;
    }
};