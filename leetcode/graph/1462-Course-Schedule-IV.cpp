
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 首先构建有向图
        vector<vector<int>> graph(n);
        for (int i = 0; i < prerequisites.size(); i++) {
            int prev = prerequisites[i][0], next = prerequisites[i][1];
            graph[prev].push_back(next);
        }

        // 创建 reachable 二维数组，reachable[i][j] 表示节点 i 到节点 j 是否可达，以及 visited 数组
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // 对每一个节点进行层序遍历，判断当前节点 i 到所有节点是否可达
        queue<int> levelQueue;
        for (int i = 0; i < n; i++) {
            levelQueue.push(i);
            while (!levelQueue.empty()) {
                int current = levelQueue.front();
                levelQueue.pop();

                for (int neighbor : graph[current]) {
                    if (visited[i][neighbor]) continue;
                    reachable[i][neighbor] = true, visited[i][neighbor] = true;
                    levelQueue.push(neighbor);
                }
            }
        }

        vector<bool> result;
        for (int i = 0; i < queries.size(); i++) {
            int prev = queries[i][0], next = queries[i][1];
            result.push_back(reachable[prev][next]);
        }
        return result;
    }
};