
#include <vector>

using namespace std;

/*
 * 简单粗暴的一个问题，将 image[sr][sc] 为起始点所连接的所有"岛屿"都变成 newColor
 */
class Solution {
private:
    int m, n;
    vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inGrid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<int>>& image, int startx, int starty, int srcColor, int newColor) {
        visited[startx][starty] = true;
        image[startx][starty] = newColor;
        for (int i = 0; i < 4; i++) {
            int x = startx + delta[i][0], y = starty + delta[i][1];
            if (inGrid(x, y) && image[x][y] == srcColor && !visited[x][y]) {
                dfs(image, x, y, srcColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() == 0 || image[0].size() == 0)
            return image;

        m = image.size(), n = image[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        dfs(image, sr, sc, image[sr][sc], newColor);

        return image;
    }
};
