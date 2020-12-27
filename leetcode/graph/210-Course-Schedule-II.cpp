#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/*
 * 拓扑排序的一个直观应用，我们只需要对 prerequisites 所组成的 Graph 进行一次拓扑排序即可
 * 如果在排序过程中发现有环，直接返回空数组即可。否则，返回排序的结果。
 * 
 * 另外需要注意的是 prerequisites 可能包含多个连通分量
 */
class Solution {
private:
    vector<int> result;
    vector<int> indegrees;
    unordered_map<int, unordered_set<int>> adjacent;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // build graph and indegrees
        indegrees = vector<int>(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            adjacent[prerequisites[i][1]].insert(prerequisites[i][0]);
            indegrees[prerequisites[i][0]] ++;
        }
        
        queue<int> zeroQueue;

        // find zero indegree
        int zeroIndegree = -1;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                zeroIndegree = i;
                zeroQueue.push(i);
            }
        }

        if (zeroIndegree == -1) return result;

        // topological sort
        while (!zeroQueue.empty()) {
            zeroIndegree = zeroQueue.front();
            zeroQueue.pop();

            result.push_back(zeroIndegree);

            for (int child: adjacent[zeroIndegree]) {
                indegrees[child] --;
                if (indegrees[child] == 0)
                    zeroQueue.push(child);
            }
        }

        if (result.size() != numCourses) {
            result.clear();
            return result;
        }

        return result;
    }
};
