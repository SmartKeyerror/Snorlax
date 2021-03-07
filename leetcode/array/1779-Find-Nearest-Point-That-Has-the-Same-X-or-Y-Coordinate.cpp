

#include <vector>
#include <climits>
#include <cmath>

using namespace std;


class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = -1, dis = INT_MAX;

        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                if (abs(points[i][0] - x) + abs(points[i][1] - y) < dis) {
                    dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                    result = i;
                }
            }
        }
        return result;
    }
};