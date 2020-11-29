

#include <vector>
#include <algorithm>

using namespace std;

/*
 * intervals 的问题本质上就是对区间如何排序的问题。
 * 在这道题中，按 interval[0] 从小到大排列，interval[1] 从大到小排列，以 [[1,2],[1,4],[3,4]] 为例，排序结果为: [1, 4], [1, 2], [3, 4]
 * 使用　current 指针来表示当前最大范围区间，初始化为　intervals[0]，而后看一看下面的区间是否被包含在当前最大区间内，若包含，则待删除区间数加１
 * 若不包含，那么我们将　current 指向该区间，作为最大区间处理。
 */
class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int current = 0, covers = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[current][0] && intervals[i][1] <= intervals[current][1])
                covers ++;
            else
                current = i;
        }

        return intervals.size() - covers;
    }
};
