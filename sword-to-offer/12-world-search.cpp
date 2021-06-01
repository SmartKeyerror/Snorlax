


/*
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 回溯法的一个典型应用场景
 * 
 */


#include <vector>
#include <queue>
#include <string>

using namespace std;


// 对于每一个 board[x][y] 来说，它可以做 3 个选择，因为一共有 4 个方向可以走，舍弃掉上一个位置，那么对于一个长度为 K 的 word 来说，我们需要做 3^K 个选择
// 同时，这个选择是在一个双重 for 循环中进行的，所以时间复杂度为 O(MN*3^K)。
// 空间复杂度为递归调用栈的最大深度，所以是 O(K)，也就是待查找字符的长度
class Solution {
private:
    int m, n;

    vector<vector<bool>> visited;

    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};     // 4 个方向，顺时针排列

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool backtracking(const vector<vector<char>>& board, const string& word, int index, int x, int y) {
        
        // 回溯终止条件
        if (index == word.size() - 1) {
            return board[x][y] == word[index];
        }

        if (word[index] != board[x][y]) return false;

        // 选择
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newx = x + delta[i][0], newy = y + delta[i][1];
            if (inBoard(newx, newy) && !visited[newx][newy]) {
                if (backtracking(board, word, index + 1, newx, newy)) return true;
            }
        }

        // 撤销选择
        visited[x][y] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtracking(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }
};
