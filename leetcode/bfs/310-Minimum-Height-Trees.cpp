
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 老规矩，将 list of edges 转换成邻接表
        vector<unordered_set<int>> record(n);
        for (int i = 0; i < edges.size(); i++) {
            record[edges[i][0]].insert(edges[i][1]);
            record[edges[i][1]].insert(edges[i][0]);
        }

        int minHigh = INT_MAX;
        vector<int> result;

        for (int i = 0; i < n; i++) {

            int height = 0;
            queue<int> levelQueue;
            vector<bool> visited(n, false);

            levelQueue.push(i);
            visited[i] = true;

            while (!levelQueue.empty()) {
                height ++;
                int size = levelQueue.size();

                for (int j = 0; j < size; j++) {
                    int current = levelQueue.front();
                    levelQueue.pop();
                    for (int child: record[current]) {
                        if (!visited[child]) {
                            levelQueue.push(child);
                            visited[child] = true;
                        }
                    }
                }
            }
            if (height < minHigh) {
                result.clear();
                result.push_back(i);
                minHigh = height;
            } else if (height == minHigh)
                result.push_back(i);
        }

        return result;
    }
};