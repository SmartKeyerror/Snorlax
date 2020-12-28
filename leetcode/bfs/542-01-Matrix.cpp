
#include <vector>
#include <queue>

using namespace std;

/*
 * 给定一个二维矩阵 matrix，求出该矩阵中每一个 1 所能达到 0 的最短距离，BFS 求解即可
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inMatrix(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();

        queue<pair<int, int>> levelQueue;
        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) levelQueue.push({i, j});
            }
        }

        while (!levelQueue.empty()) {
            int size = levelQueue.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> current = levelQueue.front();
                levelQueue.pop();
                for (int j = 0; j < 4; j++) {
                    int x = current.first + delta[j][0], y = current.second + delta[j][1];
                    if (inMatrix(x, y) && matrix[x][y] == 1 && result[x][y] == 0) {
                        levelQueue.push(make_pair(x, y));
                        result[x][y] = result[current.first][current.second] + 1;
                    }
                }                
            }
        }
        return result;
    }
};
