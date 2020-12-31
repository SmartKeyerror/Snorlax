
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
 * 滑动谜题求最少的操作次数，使得 board 达到 [[1,2,3],[4,5,0]]，其实就是小朋友玩儿的那种益智类方块儿，进阶版就是华容道。
 * 
 * 我们可以将当前 board 的整体样子看做是一个状态，我们要做的事情就是找到一条最短路径，使其状态变更为另一种状态。
 * 
 * BFS 因为有着天然的无权最短路径的优势，所以我们使用 BFS 求解即可。比较麻烦的是如何将 board 描述成一个状态?
 * 
 * - 使用整型表示: 因为是一个 2x3 的板子，所以最多会有 6 位，int 型完全没有问题，[[1,2,3],[4,5,0]] 就可以表示为 123450。
 * - 使用字符串表示: [[1,2,3],[4,5,0]] 可以表示为 "123450"，只不过使用字符串来表示的话编码会稍微复杂一些。
 * 
 * 其实，slidingPuzzle 这个问题的时间复杂度为 O(n!)，n 为 board 中的滑块数量，也就是说，当我们有一个 4x4 的板子时，使用 BFS 求解
 * 的时间复杂度为 O(16!)，这个数字其实远超过家用计算机能够处理的数据规模。
 */
class Solution {
private:
    int m, n;

    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }

    // transform board to int
    int transformBoard(vector<vector<int>>& board) {
        int result = 0, current = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                result += board[i][j] * current;
                current = current * 10;
            }
        }
        return result;
    }

    // transform int to board
    vector<vector<int>> transformInt(int current) {
        vector<int> aux;
        while (current) {
            aux.push_back(current % 10);
            current = current / 10;
        }

        if (aux.size() < m * n)
            aux.push_back(0);
        
        reverse(aux.begin(), aux.end());

        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for (int i = 0; i < aux.size(); i++)
            res[i / 3][i % 3] = aux[i];
        
        return res;
    }

    pair<int, int> findZero(vector<vector<int>>& board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) return {i, j};
            }
        }
        return {-1, -1};
    }

    // return next statuses from current status, move zero to three directions.
    vector<int> getNextStatuses(int current) {
        vector<vector<int>> curBoard = transformInt(current);
        pair<int, int> posi = findZero(curBoard);
        int x = posi.first, y = posi.second;
        
        vector<int> result;
        for (int i = 0; i < delta.size(); i++) {
            int newx = x + delta[i][0], newy = y + delta[i][1];
            if (inBoard(newx, newy)) {
                swap(curBoard[x][y], curBoard[newx][newy]);
                result.push_back(transformBoard(curBoard));
                swap(curBoard[x][y], curBoard[newx][newy]);
            }
        }
        return result;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {

        m = board.size(), n = board[0].size();

        int current = transformBoard(board);

        if (current == 123450) return 0;

        queue<int> levelQueue;
        unordered_map<int, int> visited;

        levelQueue.push(current);
        visited[current] = 0;

        while (!levelQueue.empty()) {
            current = levelQueue.front();
            levelQueue.pop();

            vector<int> nextStatuses = getNextStatuses(current);

            for (int next: nextStatuses) {
                if (visited.count(next) == 0) {
                    levelQueue.push(next);
                    visited[next] = visited[current] + 1;

                    if (next == 123450)
                        return visited[next];
                }
            }
        }
        return -1;
    }
};
