#include <vector>
#include <unordered_set>

using namespace std;

/*
 * 给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。
 * 一个点的坐标（x，y）由一个有两个整数的整数数组表示。
 * 
 * 输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * 输出: True
 * 
 * 所有输入整数都在 [-10000，10000] 范围内。
 * 
 * 可以这样来做，计算所有两点间的距离，最终只会得到两种不同的距离
 */

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        unordered_set<int> distances;

        distances.insert((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
        distances.insert((p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]));
        distances.insert((p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]));

        distances.insert((p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]));
        distances.insert((p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]));

        distances.insert((p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]));

        if (distances.size() != 2) return false;

        // 边长和对角线不允许为 0
        for (auto dis : distances) {
            if (dis == 0) return false;
        }
        return true;
    }
};