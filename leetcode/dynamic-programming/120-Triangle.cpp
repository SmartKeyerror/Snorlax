
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;


/*
 * Runtime: 8 ms, faster than 91.25% of C++ online submissions for Triangle.
 */
class Solution {
private:

    // 保存 triangle[i][j] 向下的最短路径和
    vector<vector<int>> memory;

    int minimum(vector<vector<int>>& triangle, int x, int y) {

        if (x == triangle.size() - 1)
            return triangle[x][y];
        
        if (memory[x][y] == -1)
            memory[x][y] = min(minimum(triangle, x + 1, y), minimum(triangle, x + 1, y + 1)) + triangle[x][y];

        return memory[x][y];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        memory = vector<vector<int>>(triangle.size(), vector<int>{});

        for (int i = 0; i < triangle.size(); i++) {
            memory[i] = vector<int>(triangle[i].size(), -1);
        }

        return minimum(triangle, 0, 0);
    }
};