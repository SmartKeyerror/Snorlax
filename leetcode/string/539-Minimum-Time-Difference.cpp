
#include <vector>
#include <string>
#include <climits>

using namespace std;


class Solution {
private:
    int getMinDifference(const string &a, const string &b) {
        int hourDiff = stoi(a.substr(0, 2)) - stoi(b.substr(0, 2));
        int minuteDiff = stoi(a.substr(3, 2)) - stoi(b.substr(3, 2));
        return min(hourDiff * 60 + minuteDiff, 1440 - (hourDiff * 60 + minuteDiff));
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        
        int res = INT_MAX;
        for (int i = 1; i < n; i++)
            res = min(res, getMinDifference(timePoints[i], timePoints[i-1]));
        
        // 还有一个环需要处理，也就是 timePoints[0] 和 timePoints[n-1] 这两个时间
        res = min(res, getMinDifference(timePoints[n-1], timePoints[0]));
        return res;
    }
};
