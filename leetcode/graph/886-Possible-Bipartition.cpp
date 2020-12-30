
#include <vector>

using namespace std;

/*
 * 本质上是一个二分图检测的问题，只不过部分的横切边通过 dislikes 给出。所以，我们要做的事情就是对 dislikes 这个图进行 bipartition。
 * 
 * 依然使用染色的方式完成，当对 dislikes 这个图进行染色后，若发现冲突，那么这 N 个人一定不能被分在同一组，反之则可以。
 * 
 * Runtime: 332 ms, faster than 93.60% of C++ online submissions for Possible Bipartition.
 * Memory Usage: 65.5 MB, less than 56.10% of C++ online submissions for Possible Bipartition.
 */
class Solution {
private:

    // -1: not visited, 0: red, 1: blue
    vector<int> visited;

    bool dfs(vector<vector<int>> &graph, int current, int color) {
        visited[current] = color;
        for (int child: graph[current]) {
            if (visited[child] != -1 && visited[child] == visited[current]) return false;
            if (visited[child] == -1) {
                if (!dfs(graph, child, 1 - color)) return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

        visited = vector<int>(N + 1, -1);

        vector<vector<int>> graph(N + 1, vector<int>());
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for (int i = 1; i < N; i++) {
            if (visited[i] != -1 && !dfs(graph, i, 0))
                return false;
        }
        return true;
    }
};
