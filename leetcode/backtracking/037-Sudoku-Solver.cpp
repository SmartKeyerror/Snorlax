#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
private:
    // 使用 set 来快速判断当前选择是否合法
    vector<unordered_set<char>> row  = vector<unordered_set<char>>(9, unordered_set<char>());
    vector<unordered_set<char>> col  = vector<unordered_set<char>>(9, unordered_set<char>()); 
    vector<unordered_set<char>> cell = vector<unordered_set<char>>(9, unordered_set<char>());

    void initSet(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current == '.') continue;
                row[i].insert(current); col[j].insert(current);
                cell[(i / 3) * 3 + j / 3].insert(current);
            }
        }
    }

    bool isValid(int i, int j, char val) {
        if (row[i].count(val)) return false;
        if (col[j].count(val)) return false;
        if (cell[(i / 3) * 3 + j / 3].count(val)) return false;
        return true;
    }

    // 尝试对 board[i][j] 进行填充, i、j 的运动规则为从左至右、从上至下
    bool backtracking(vector<vector<char>>& board, int i, int j) {

        if (j == 9) {
            i ++; j = 0;
        }

        if (i == 9) return true;

        if (board[i][j] != '.')
            return backtracking(board, i, j + 1);
        
        for (int k = 1; k <= 9; k++) {
            char val = k + '0';
            if (!isValid(i, j, val)) continue;

            board[i][j] = val;
            row[i].insert(val), col[j].insert(val);
            cell[(i / 3) * 3 + j / 3].insert(val);

            if (backtracking(board, i, j + 1)) return true;

            board[i][j] = '.';
            row[i].erase(val), col[j].erase(val);
            cell[(i / 3) * 3 + j / 3].erase(val);
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        initSet(board);
        backtracking(board, 0, 0);
    }
};
