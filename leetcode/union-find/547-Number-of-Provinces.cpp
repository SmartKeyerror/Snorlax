
#include <vector>

#include "union_find.h"

using namespace std;

/*
 * 本质上就是求一个邻接矩阵所代表的图中的连通分量的个数，DFS、BFS 以及 union-find 都能够解决该问题。
 */
class Solution {
private:
    // Runtime: 80 ms, faster than 10.10% of C++ online submissions for Number of Provinces.
    // Memory Usage: 14.1 MB, less than 76.35% of C++ online submissions for Number of Provinces.
    // wtf ??
    int unionFindSolution(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf = UnionFind(n);

        // 我们并不需要遍历整个 isConnected 二维数组，只需要取后半部分即可，因为它是根据角对角线对称的。
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1)
                    uf.unionNode(i, j);
            }
        }
        return uf.getCCNums();
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        return unionFindSolution(isConnected);
    }
};