
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;

/*
 * 非常直白的回溯问题， 从二维数组 board[0][0] 出发，前进方向为 上、右、下、左， 即顺时针进行
 * 二维回溯在“前进”时，可使用一个辅助的二维数组协助获得终点坐标
 */
class Solution {
private:
    vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited;

    int m, n;

    bool inBoard(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 在 board[startx][starty] 中搜索 word[index]
    bool search(vector<vector<char>>& board, string word, int index, int startx, int starty) {

        // 终止条件: 当前路径已经抵达字符串的末尾，此时需要比较当前 board[startx][starty] 和 word[index] 是否相等即可
        if (index == word.size() - 1)
            return board[startx][starty] == word[index];
        
        if (board[startx][starty] == word[index]) {

            // 在4个方向上进行选择, 并且新的坐标需要在二维数组内，并且未曾访问过某一个方向上的元素

            visited[startx][starty] = true;

            for (int i = 0; i < 4; i++) {
                int newx = startx + delta[i][0];
                int newy = starty + delta[i][1];

                if (inBoard(newx, newy) && !visited[newx][newy]) {
                    if (search(board, word, index + 1, newx, newy))
                        return true;
                }
            }

            // 撤销选择
            visited[startx][starty] = false;
        }

        return false;

    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        // 初始化 visited 数组
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (search(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};