
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 挺有意思的一道题目，这种“感染”类型的模拟在计算机领域中应该有很广阔的应用。
 * 
 * 题目不再描述了，思路如下:
 * 
 * 首先我们得找到所有的腐烂🍊的位置，这些都是 BFS 的起始位置，也就是都需要首先扔到队列里面去的。其次就是找到所有完好的🍊，用于后续的“连通分量”个数的判断，也就是
 * 判断是不是能将所有的🍊都感染的依据。
 * 
 * 然后就是中规中矩的 BFS 过程了，每一次遍历都只能向下走一层，直到队列为空为止。
 * 
 * 另外值得一提的就是我们可以不使用 visited 数组，在每层遍历的时候，只需要将完好的🍊更新为腐烂的🍊即可，反正我们对腐烂的🍊也不关心。
 * 
 * Runtime: 12 ms, faster than 60.49% of C++ online submissions for Rotting Oranges.
 * Memory Usage: 14 MB, less than 23.02% of C++ online submissions for Rotting Oranges.
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        m = grid.size(), n = grid[0].size();

        // 首先，我们需要找到所有腐烂🍊的位置，以及完好🍊的个数
        int fresh = 0;
        vector<vector<int>> rottens;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) rottens.push_back({i, j});
                else if (grid[i][j] == 1) fresh ++;
            }
        }
        if (fresh == 0) return 0;

        if (rottens.size() == 0) return -1;

        queue<pair<int, int>> levelQueue;

        for (int i = 0; i < rottens.size(); i++)
            levelQueue.push(make_pair(rottens[i][0], rottens[i][1]));
        
        int count = 0, currentFresh = fresh;

        while (!levelQueue.empty()) {
            int size = levelQueue.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> current = levelQueue.front();
                levelQueue.pop();

                int startx = current.first, starty = current.second;
                for (int j = 0; j < 4; j++) {
                    int x = startx + delta[j][0], y = starty + delta[j][1];
                    if (inGrid(x, y) && grid[x][y] == 1) {
                        currentFresh --;
                        grid[x][y] = 2;
                        levelQueue.push(make_pair(x, y));
                    }
                }
            }
            count ++;
        }

        // 如果此时仍然存在未腐烂的🍊，说明 grid 中存在多个 “连通分量”，不可能完全“感染”所有的🍊。
        if (currentFresh) return -1;

        return count - 1;
    }
};
