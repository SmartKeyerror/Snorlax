
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<vector<int>> delta = {{1, 0}, {0, 1}};

    int m, n;
    vector<vector<int>> memory;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void processRow(vector<vector<int>> &obstacleGrid) {
        int rowSword = m - 1;
        for (int row = 0; row < m; row++) {
            if (obstacleGrid[row][0] == 1) {
                rowSword = row;
                memory[row][0] = 0;
            }
            else if (row > rowSword) {
                memory[row][0] = 0;
            }
            else
                memory[row][0] = 1;
        }
    }

    void processCol(vector<vector<int>>& obstacleGrid) {
        int colSword = n - 1;
        for (int col = 0; col < n; col++) {
            if (obstacleGrid[0][col] == 1) {
                colSword = col;
                memory[0][col] = 0;
            }
            else if (col > colSword)
                memory[0][col] = 0;
            else
                memory[0][col] = 1;
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        assert(obstacleGrid.size() > 0);

        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        memory = vector<vector<int>>(m, vector<int>(n, 0));

        processRow(obstacleGrid);
        processCol(obstacleGrid);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (obstacleGrid[i][j-1] != 1)
                    memory[i][j] += memory[i][j-1];

                if (obstacleGrid[i-1][j] != 1)
                    memory[i][j] += memory[i-1][j];
            }
        }
            
        return memory[m-1][n-1];
    }
};

int main() {
    Solution s = Solution();

    vector<vector<int>> obstacleGrid = {{0, 1, 0}, {1, 1, 0}, {0, 0, 0}};

    printf("%d \n", s.uniquePathsWithObstacles(obstacleGrid));
}
