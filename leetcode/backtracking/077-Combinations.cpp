
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

/*
 * 剪枝, 类似问题: Combination Sum， Combination Sum II， Combination Sum III, Subsets
 */
class Solution {
private:
    vector<vector<int>> result;

    // 从 start...n 中求解组合问题, selected为已选择路径
    void combination(int n, int k, int start, vector<int> &selected) {

        if (selected.size() == k) {
            result.push_back(selected);
            return;
        }

        /*
         * 此处可进行剪枝
         * 到这里， 我们已经选择了 selected.size() 这么多个元素， 总的选取数量为 k ，还剩下 k - selected.size() 个元素需要选取
         * 也就是说，在 [i...n] 之间至少应该存在 k - selected.size() 这个多个元素
         * 那么 i 完全不必要一直自增到 n，只需要自增到剩下的元素区间无法满足选取 k - selected.size() 这么多个元素数量即可。
         * 
         * 这其实就是剪枝
         */
        for (int i = start; i <= n - (k - selected.size()) + 1; i++) {
            selected.push_back(i);
            combination(n, k, i + 1, selected);
            selected.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {

        assert(n > 0 && k > 0 && k <= n);

        vector<int> selected;
        combination(n , k, 1, selected);

        return result;
    }
};
