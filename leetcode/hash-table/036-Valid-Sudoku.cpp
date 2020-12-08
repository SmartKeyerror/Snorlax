
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * 验证初始化数独是否正确，也就是验证每一行、每一列、每一个 3*3 的单元格内是否存在相同的元素
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9, unordered_set<int>());
        vector<unordered_set<int>> col(9, unordered_set<int>());
        vector<unordered_set<int>> cell(9, unordered_set<int>());

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                
                char current = board[i][j];
                if (current == '.') continue;
                
                int num = current - '0';
            
                if (row[i].count(num)) return false;
                if (col[j].count(num)) return false;                
                if (cell[(i / 3) * 3 + j / 3].count(num)) return false;

                row[i].insert(num);
                col[j].insert(num);
                cell[(i / 3) * 3 + j / 3].insert(num);
            }
        }
        return true;
    }
};
