
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct heapCompare {
    bool operator() (vector<int> &a, vector<int> &b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    }
};

class Solution {

private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    }

    // 暴力解法，根据 points[0][1] 排序，返回 points[k]
    // Runtime: 476 ms, faster than 38.11% of C++ online submissions for K Closest Points to Origin.
    vector<vector<int>> brouteSolution(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), cmp);
        return {points.begin(), points.begin() + K};
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        return brouteSolution(points, K);
    }
};