
#include <vector>
#include <queue>

using namespace std;

/*
 * 将题目翻译以下，其实就是求两个岛屿之间的最短距离。
 * 
 * 如果是二维坐标中两个点的最短距离，直接使用 BFS 求解即可。那么对于两个岛屿来说，岛屿是由点所构成的，所以本质上还是求解点与点之间的距离。
 * 
 * 只不过在这里我们需要对整个岛的所有点同时进行 BFS，类似于海水涨潮这样的感觉，所有点一层一层往下推。
 * 
 * 也就是说，我们需要首先找到一个岛屿，将其与该岛屿相连接的所有的 `1` 都丢入队列之中，然后执行 BFS。
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    queue<pair<int, int>> levelQueue;

    // dfs 寻找第一座岛屿所有的点
    void dfs(vector<vector<int>>& A, int startx, int starty) {
        visited[startx][starty] = true;
        levelQueue.push({startx, starty});
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inBoard(x, y) && !visited[x][y] && A[x][y] == 1)
                dfs(A, x, y);
        }
    }

    // bfs 寻找两个岛屿间的最短距离
    int bfs(vector<vector<int>>& A) {
        int count = 0;
        while (!levelQueue.empty()) {
            count ++;
            int size = levelQueue.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> current = levelQueue.front();
                levelQueue.pop();
                int startx = current.first, starty = current.second;
                for (int j = 0; j < 4; j++) {
                    int x = startx + delta[j][0], y = starty + delta[j][1];
                    if (!inBoard(x, y) || visited[x][y]) continue;
                    visited[x][y] = true;
                    if (A[x][y] == 1) return count - 1;
                    levelQueue.push({x, y});
                }
            }
        }
        return -1;
    }

    
public:
    int shortestBridge(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j);
                    return bfs(A);
                }
            }
        }
    }
};
