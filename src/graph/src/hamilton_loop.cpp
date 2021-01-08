
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


class HamiltonLoop {
private:
    vector<bool> visited;
    vector<unordered_set<int>> graph;
    vector<vector<int>> loops;

    void backtracking(int src, int current, int left, vector<int>& path) {
        if (left == 0 && current == src) {
            loops.push_back(path);
            return ;
        }
        for (int next : graph[current]) {
            if (!visited[next]) {
                left --;
                visited[next] = true;
                path.push_back(next);

                backtracking(src, next, left, path);

                left ++;
                visited[next] = false;
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> getAllLoop(int vertices, vector<vector<int>> edges) {
        visited = vector<bool>(vertices, false);
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        vector<int> loop;
        loop.push_back(0);
        backtracking(0, 0, vertices, loop);

        return loops;
    }
};


int main() {
    int vertives = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,0}};

    vector<vector<int>> result = HamiltonLoop().getAllLoop(vertives, edges);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}
