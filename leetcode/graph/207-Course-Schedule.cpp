
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * 具有多个连通分量的有向图进行环检测，prerequisites 以 list of edges 给出，个人比较习惯转换成邻接矩阵或者是邻接表来做
 */
class Solution {
private:
    vector<int> visited;
    unordered_map<int, unordered_set<int>> adjacent;

    bool hasCycle(unordered_map<int, unordered_set<int>> &adjacent, int current) {
        visited[current] = 1;
        for (int next: adjacent[current]) {
            if (visited[next] == 1) return true;
            if (hasCycle(adjacent, next)) return true;
        }
        visited[current] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        for (int i = 0; i < prerequisites.size(); i++)
            adjacent[prerequisites[i][1]].insert(prerequisites[i][0]);
        
        // 0: not visited, 1: processing, 2: visited
        visited = vector<int>(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(adjacent, i)) 
                    return false;
            }
        }
        return true;
    }
};
