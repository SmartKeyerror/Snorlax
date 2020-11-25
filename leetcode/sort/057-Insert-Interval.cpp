#include <vector>
#include <algorithm>

using namespace std;

/*
 * 在一个原本不重叠的区间列表中添加一个区间，返回融合后的区间列表
 * 
 * [[1,3],[6,9]] => [2,5]
 * [[1,5],[6,9]]
 * 
 * [[1,2],[3,5],[6,7],[8,10],[12,16]] => [4,8]
 * [[1,2],[3,10],[12,16]]
 * 
 * 一个最简单的方法就是参照 56. Merge Intervals 的思路，将 newInterval 丢到 intervals 中。
 * 排序，再尝试去 merge 区间，能 merge 就 merge，merge 不了就直接输出，整体复杂度为 O(nlogn)
 * 
 * 这么做的好处就是代码复用，直接 CV 大法(笑
 */
class Solution {
private:
    vector<vector<int>> result;

    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
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
        result.push_back({start, end});
        return result;
    }

    // Runtime: 56 ms, faster than 16.55% of C++ online submissions for Insert Interval.
    // Memory Usage: 17.7 MB, less than 20.77% of C++ online submissions for Insert Interval.
    // 使用 mergeIntervals 的思路成绩比较惨淡
    vector<vector<int>> mergeIntervalsUseSort(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), cmp);

        return mergeIntervals(intervals);
        
    }

    // 既然直接插入并排序是算法的主要耗时点，那么我们完全可以使用二分插入的方式完成
    // 虽然平均时间复杂度也是 O(nlogn)，但是实际操作数量要小于上面的方法
    // Runtime: 24 ms, faster than 86.51% of C++ online submissions for Insert Interval.
    // 虽然平均时间复杂度同为 O(nlogn)，但是实际执行时间却少了一半多
    vector<vector<int>> mergeIntervalsUseBisert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = 0, right = intervals.size() -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] == newInterval[0]){
                left = mid;
                break;
            }
            else if (intervals[mid][0] < newInterval[0]) left = mid + 1;
            else right = mid - 1;
        }
        intervals.insert(intervals.begin() + left, newInterval);

        return mergeIntervals(intervals);
    }


public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // return mergeIntervalsUseSort(intervals, newInterval);
        return mergeIntervalsUseBisert(intervals, newInterval);
    }
};
