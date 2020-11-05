#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

/*
 * 全排列问题， 本质上是一棵决策树的遍历，我们对一棵决策树的一部分进行解释，假设 nums = [1, 2, 3, 4]
 * 
 *             1
 *            /
 *           2      
 *          / \    
 *         3   4
 * 
 * 当我们固定第一个元素为 1 时，剩下可供选择的元素列表即为 [2, 3, 4]，如上图所示，在选择第二个元素时选择了元素 2
 * 当固定了元素 2 以后，那么此条路径可供选择的元素就只剩下 [3, 4]了， 当选择 3 时， 此条路径的排列为 [1, 2, 3]，最后剩下元素 4, 所以组成一个排列 [1, 2, 3, 4]
 * 当我们组成一个排列之后呢？ 在选择 [3, 4] 时我们做了其中一种选择，现在，我们需要回到此处，再做一次不一样的选择，那么此时我们就需要将 [1, 2, 3] 中的选择撤销掉，重新变成 [1, 2]， 然后再做选择
 * 
 * 那么从上方的描述中就可以看到，首先我们需要保存 已确定或者说已选择的路径，其次就是下一次进行选择时，有哪些可选选项
 */
class Solution {

private:
    vector<vector<int>> result;

    /*
     * nums: 待排列数组
     * selected: 已选择的路径
     * 终止条件: 已选择的路径长度等于待排列数组长度
     */
    void backtracing(vector<int> &nums, vector<int> selected) {

        if (nums.size() == selected.size()) {
            result.push_back(selected);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 如果当前元素已经在 selected 数组中的话， continue
            if (count(selected.begin(), selected.end(), nums[i]))
                continue;
            
            // 进行选择，也就是把当前 nums[i] 追加到 已选择列表中
            selected.push_back(nums[i]);

            backtracing(nums, selected);

            // 撤销选择
            selected.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        
        vector<int> selected;
        selected.clear();

        backtracing(nums, selected);

        return result;   
    }
};