
#include <vector>
#include <unordered_map>

using namespace std;


/*
 * 给定一个数量为 n 的二维坐标 points，求三元组 (i, j, k)，使得 i 到 j 的距离等于 i 到 k 的距离，即 j→i == i←k
 * 
 * 我们可以看到，节点 i 是一个枢纽节点，连接着 j 和 k。如果我们把所有到达点 i 的距离频次输出到一个哈希表中，再来统计频次即可获得答案
 */
class Solution {
private:
    int distance(vector<int> &a, vector<int> &b) {
        // 不进行开方运算，避免出现浮点数(精度丢失)
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> record;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                record[distance(points[i], points[j])] ++;
            }
            for (auto &item: record)
                result += item.second * (item.second - 1);
        }
        return result;
    }
};
