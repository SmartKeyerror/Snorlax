
#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>

using namespace std;


class EulerLoop {
private:
    vector<unordered_set<int>> graph;
    vector<int> loop;
public:
    bool hasEulerLoop() {
        // 计算每一个顶点的度，如果某一个顶点的度为奇数的话，不存在欧拉回路
        for (auto edges : graph) {
            if (edges.size() & 1) return false;
        }
        return true;
    }

    vector<int> getEulerLoop(int vertices, vector<vector<int>> edges) {
        loop.clear();
        graph = vector<unordered_set<int>>(vertices);

        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        if (!hasEulerLoop()) return loop;

        stack<int> path;
        int current = 0;
        path.push(current);

        while (!path.empty()) {
            if (graph[current].size() != 0) {
                path.push(current);
                // 随便找一个 current 的相邻顶点，C++可用迭代器实现。删边
                int random = *graph[current].begin();
                graph[current].erase(random);
                graph[random].erase(current);
                current = random;
            }
            else {
                loop.push_back(current);
                current = path.top();
                path.pop();
            }
        }
        return loop;
    } 
};


int main() {
    int vertives = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2},{2,3},{3,4},{4,2}};

    vector<int> result = EulerLoop().getEulerLoop(vertives, edges);

    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<", ";
    }
    cout<<endl;

    return 0;
}
