
#include <vector>

using namespace std;

/*
 * 扫雷小游戏~
 * 
 * 'M' 表示藏着的雷，'E' 表示藏着的安全区域，'B' 表示公开的区域，并且该格子的 8 个方向上都没有雷，
 * '1~8' 表示当前格子周围有多少个雷，'X' 表示已经公开的雷。
 * 
 * 游戏规则，给定下一次的点击位置，计算出点击后 board 的样子
 * - 当点击到 'M' 时，将点击区域改变为 'X'，并且游戏结束
 * - 当点击到 'E' 时，如果该格子的 8 个方向都没有雷的话，将其更新为 'B'，并且尽可能地扩大 'B' 的区域
 * - 当点击到 'E' 时，如果该格子的 8 个方向有雷的话，将其更新成 8 个方向上存在雷的数量
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<char>>& board, int startx, int starty) {
        int count = 0;

        // 计算 board[startx][starty] 周围的雷的数量
        for (int i = 0; i < 8; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inBoard(x, y) && (board[x][y] == 'M' || board[x][y] == 'X'))
                count ++;
        }

        if (count == 0) board[startx][starty] = 'B';
        else board[startx][starty] = count + '0';

        // 只有当 board[startx][starty] == 'B' 的时候，我们才应该向外扩展疆土
        if (count != 0) return;
        
        // 开疆扩土!
        for (int i = 0; i < 8; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inBoard(x, y) && board[x][y] == 'E')
                dfs(board, x, y);
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        
        int startx = click[0], starty = click[1];

        if (board[startx][starty] == 'M') {
            board[startx][starty] = 'X';
            return board;
        }

        dfs(board, startx, starty);

        return board;
    }
};