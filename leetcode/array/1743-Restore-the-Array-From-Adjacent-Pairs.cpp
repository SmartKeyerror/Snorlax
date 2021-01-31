#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        unordered_map<int, vector<int>> graph;

        for (auto pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> edges;
        for (auto item : graph)
            if (item.second.size() == 1) edges.push_back(item.first);

        vector<int> res;

        int start = edges[0];
        res.push_back(start);
        int current = graph[start][0];
        graph.erase(start);

        for (int i = 0; i < adjacentPairs.size(); i++) {
            res.push_back(current);            
            for (auto next : graph[current]) {
                if (graph.count(next)) {
                    graph.erase(current);
                    current = next;
                    break;
                }
            }
        }

        return res;
    }
};