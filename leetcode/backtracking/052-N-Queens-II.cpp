
#include <vector>
#include <string>

using namespace std;

class Solution {

private:

    int result = 0;

    // 这里需要使用 3 个 vector 来表示对应列、左对角线、右对角线中是否存在已摆放的皇后
    // 其中 colPuted 长度为 n, leftDiagonalPuted 与 rightDiagonalPuted 的长度为 2n - 1
    vector<bool> colPuted, leftDiagonalPuted, rightDiagonalPuted;

    // 这里使用一个 一维数组 来保存已选择的路径，因为每一行一定只有一个皇后，所以 selected 的 index 即表示行, selected[index] 表示列

    // 在一个 n 皇后问题中，在第 index 行中摆放皇后
    void backtracking(int n, int index, vector<int> &selected) {
        if (selected.size() == n) {
            result ++;
            return;
        }

        // 尝试向第 index 行、第 i 列中摆放皇后
        for (int i = 0; i < n; i++) {
            
            // 因为 横坐标 - 纵坐标 会有负数，所以加上一个 n - 1，使其范围在 [0..2n-1)
            if (colPuted[i] || leftDiagonalPuted[index - i + n - 1] || rightDiagonalPuted[index + i])
                continue;
            
            colPuted[i] = true;
            rightDiagonalPuted[index + i] = true;
            leftDiagonalPuted[index - i + n - 1] = true;
        
            selected.push_back(i);

            backtracking(n, index + 1, selected);

            selected.pop_back();

            leftDiagonalPuted[index - i + n - 1] = false;
            rightDiagonalPuted[index + i] = false;
            colPuted[i] = false;
        }

        return;
    }

public:
    int totalNQueens(int n) {
        colPuted = vector<bool>(n, false);
        leftDiagonalPuted = vector<bool>(2*n-1, false);
        rightDiagonalPuted = vector<bool>(2*n-1, false);

        vector<int> selected;

        backtracking(n, 0, selected);

        return result;
    }
};
