
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits.h>

using namespace std;

/*
 * 对每一个节点进行 BFS 将会导致 TLE。
 * 
 * 另外一种解法，从叶子节点(也就是度为0的节点)开始，一层一层的进行删除，直到剩下 1 个或者是 2 个节点，那么这两个节点就是我们所需要的根节点。
 */
class Solution {
private:
    vector<int> onionSolution(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<unordered_set<int>> record(n);
        for (int i = 0; i < edges.size(); i++) {
            record[edges[i][0]].insert(edges[i][1]);
            record[edges[i][1]].insert(edges[i][0]);
        }

        queue<int> levelQueue;
        for (int i = 0; i < n; i++) {
            if (record[i].size() == 1) levelQueue.push(i);
        }

        while (n > 2) {
            int size = levelQueue.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int current = levelQueue.front();
                levelQueue.pop();
                for (int next : record[current]) {
                    record[next].erase(current);
                    // levelQueue 仅处理叶子节点
                    if (record[next].size() == 1) levelQueue.push(next);
                }
            }
        }

        vector<int> result;
        while (!levelQueue.empty()) {
            result.push_back(levelQueue.front());
            levelQueue.pop();
        }
        return result;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        return onionSolution(n, edges);
    }
};
