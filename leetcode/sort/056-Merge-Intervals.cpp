
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 在数学的定义上，如果两个区间([p, q], [h, k])相交的话， 必然存在 p <= h <= q
 * 所以，首先对这个二维数组排序。好在该数组并不复杂，只需要对 intervals[i][0] 进行判断即可，时间复杂度近似为 nlogn
 * 
 * 而后我们遍历一遍 intervals, 逐一地合并每一个应该并合并的区间
 */
class Solution {
private:

    vector<vector<int>> result;

    static bool cmp(vector<int> &a, vector<int> &b) {
        // todo: 为什么这里不能是 a[0] <= b[0] ?
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        if (intervals.size() == 0)
            return result;
        
        sort(intervals.begin(), intervals.end(), cmp);

        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        // 还有最后一组区间没有被压入 result, 需要注意下
        result.push_back({start, end});
        return result;
    }
};
