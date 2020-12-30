
#include <vector>

using namespace std;

/*
 * 求图中 src 到 dst 的全部路径，Graph 以邻接表的形式给出。
 */
class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> result;
    
    void dfs(vector<vector<int>>& graph, int current, int dst, vector<int> &path) {

        if (current == dst) {
            result.push_back(path);
            return ;
        }

        for (int child: graph[current]) {
            visited[current] = true;
            if (!visited[child]) {
                path.push_back(child);
                dfs(graph, child, dst, path);
                path.pop_back();
            }
            visited[current] = false;
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        visited = vector<bool>(graph.size(), false);
        path.push_back(0);
        dfs(graph, 0, graph.size() - 1, path);
        return result;
    }
};