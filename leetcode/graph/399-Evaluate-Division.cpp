
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>


using namespace std;

/*
 * 挺有意思的一道题目，给定一组 a/b、b/d 这样的 equations 以及它们的值 values，进而查询 a/b、b/d 等运算结果。
 * 
 * 我们可以建立一张有向图，并且相邻顶点间存在两条边，a/b = 2.0 可以表示成顶点 a 到顶点 b 的权值为 2.0，那么 b 到 a 的权值就是其倒数，即 1 / 2.0 = 0.5。
 * 
 * 当我们知道了 a/b = 2.0 以及 b/c = 3.0 之后，a/c = a/b * b/c = 6.0，同样的我们也知道了 c/a = 1 / 6.0。
 * 
 * 如此一来，我们就有了两种选择，一种方式是根据 equations 建立一张稠密图，而后 O(1) 的时间复杂度进行查询。
 * 
 * 另一种方式则是每次查询时都进行一次 BFS 或者时 DFS 来寻找起点到终点的路径，取所有路径权值的乘积即可。
 * 
 * 因为题目中给出了 1 <= Ai.length, Bi.length <= 5 这个限制条件，所以建立稠密图的代价并不是很高，因此我使用第一种方式进行求解。
 */
class Solution {
private:
    unordered_set<string> visited;
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(string src, string dst) {
        if (!graph.count(src) || !graph.count(dst)) return -1;

        if (graph[src].count(dst)) return graph[src][dst];
        
        if (src == dst) return 1.0;

        visited.insert(src);

        for (auto child : graph[src]) {
            if (!visited.count(child.first)) {
                double current = dfs(child.first, dst);
                if (current != -1.0) 
                    return current * child.second;
            }
        }
        return -1;
    }

    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].insert({equations[i][1], values[i]});
            graph[equations[i][1]].insert({equations[i][0], 1 / values[i]});
        }

        vector<double> result;
        for (int i = 0; i < queries.size(); i++) {
            visited.clear();
            double res = dfs(queries[i][0], queries[i][1]);
            result.push_back(res);
        }
        return result;
    }
};
