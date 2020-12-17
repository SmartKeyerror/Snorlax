
#include <vector>

using namespace std;

/*
 * “你们已经被我包围了!”，将被 'X' 完全包围的 'O' 转换成 'X'，有点儿圈地盘儿的意思。同样的，4 条边不在包围的范畴内
 * 
 * 有两个选择，在"圈地盘儿"的过程中进行转化，一旦发现无法形成完整的包围圈，再将转化的那些底盘变回去。也就是一个 dfs 搞定
 * 另外一个选择就是一拨人圈地，确定能够形成完整的包围圈滞之后，另一拨人再去转换地盘。这种方式可能需要对同一片区域做两次 dfs
 * 
 * 使用两次 dfs 代码看起来要简单一些，我脑子不太够用，所以选简单的。
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool inEdge(int x, int y) {
        return x == 0 || y == 0 || x == m -1 || y == n - 1;
    }

    void enclosure(vector<vector<char>>& board, int startx, int starty, bool &flag) {
        visited[startx][starty] = true;
        if (inEdge(startx, starty)) flag = false;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inBoard(x, y) && board[x][y] == 'O' && !visited[x][y])
                enclosure(board, x, y, flag);
        }
    }

    void transform(vector<vector<char>>& board, int startx, int starty) {
        board[startx][starty] = 'X';
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inBoard(x, y) && board[x][y] == 'O')
                transform(board, x, y);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return ;

        m = board.size(), n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool flag = true;
                    enclosure(board, i, j, flag);
                    if (flag) transform(board, i, j);
                }
            }
        }
    }
};