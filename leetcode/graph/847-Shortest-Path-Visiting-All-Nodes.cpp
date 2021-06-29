
#include <vector>
#include <queue>

using namespace std;

/* 
 * 给出 graph 为有 N 个节点（编号为 0, 1, 2, ..., N-1）的无向连通图。 
 * graph.length = N，且只有节点 i 和 j 连通时，j != i 在列表 graph[i] 中恰好出现一次。
 * 返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。
 * 
 * 输入：[[1,2,3],[0],[0],[0]]
 * 输出：4
 * 解释：一个可能的路径为 [1,0,2,0,3]
 * 
 * 此时无向图的样子为:  
 *       0
 *     / | \
 *    1  2  3
 * 
 * 如果从 0 出发，遍历所有节点的成本为 6；如果从 1 出发，成本为 4；从 2 出发，成本为 4；从 3 出发，成本为 4
 * 
 * 输入：[[1],[0,2,4],[1,3,4],[2],[1,2]]
 * 输出：4
 * 解释：一个可能的路径为 [0,1,4,2,3]
 * 
 * 此时无向图的样子为:
 * 
 *     0
 *    /
 *   1 — 2 - 3
 *    \ /
 *     4  
 * 
 *  从 0 出发，成本为 4；从 1 出发，成本为 5；从 2 出发，成本为 5；从 3 出发，成本为 4
 * 
 * 最短路径问题通常可以考虑使用 BFS 进行求解，并且这道题目并没有给出起点，所以可以考虑 多起点+BFS。
 * 
 * 但是，因为题目要求遍历完所有节点，并且边可以重复使用，如果单纯的使用 visited 数组的话，
 * 每次从队列取出节点都需要遍历一遍 visited 数组，这样一来时间复杂度就上去了。
 * 
 * visited 数组在图论领域中还可以使用状态压缩，也就是使用 int 或者是 long long 来表示，由于 N <= 10，所以 int 足以。
 * 
 * 假如我们从节点 3 出发，那么 visited 可以表示为 1 << 3。当进入到节点 4 时，就可以表示为 1 << 3 | 1 << 4。
 * 
 * 假如图中共有 5 个节点，遍历完所有节点以后，visited 一定会变成 11111，也就是 (1 << 5) - 1
 */

class State {
public:
    int node, cover;
    State(int _node, int _cover) : node(_node), cover(_cover) {}
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // 计算终止状态
        int n = graph.size();
        int finish = (1 << n) - 1;

        // 为什么还需要 visited 数组呢? 因为边可以重复使用，所以我们需要避免出现死循环的情况
        // 并且我们以 State.cover 的值来作为判断依据
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        queue<State> levelQueue;

        // 将所有起点纳入
        for (int i = 0; i < n; i++) {
            levelQueue.push(State(i, 1 << i));
        }

        int level = 0;
        while (!levelQueue.empty()) {
            int size = levelQueue.size();

            for (int i = 0; i < size; i++) {
                State current = levelQueue.front();
                levelQueue.pop();

                // 找到了满足条件的节点
                if (current.cover == finish) return level;

                // 判断是否已经遍历过了
                if (visited[current.node][current.cover]) continue;

                visited[current.node][current.cover] = true;

                // 将相邻节点压入队列
                for (const auto neighbor : graph[current.node]) {
                    levelQueue.push(State(neighbor, current.cover | (1 << neighbor)));
                }
            }

            level ++;
        }
        return -1;
    }
};
