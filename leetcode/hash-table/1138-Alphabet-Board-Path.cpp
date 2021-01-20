
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 在一个仅包含小写英文字母的板子上找最短路径，并将该路径通过特殊的表现形式表现出来。
 * 
 * 这道题的最短路径如果用 BFS 来做的话就会变得比较复杂，移动方向在 4 个方向上，并且没有障碍物。对于任意的一个 src 和 dst ，直上直下+转弯就是最短的那条路径
 * 
 */
class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        unordered_map<char, pair<int, int>> record;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                record[board[i][j]] = {i, j};

        string res = "";        
        int x = 0, y = 0;

        for (int i = 0; i < target.size(); i++) {
            int dstx = record[target[i]].first, dsty = record[target[i]].second;

            if (y > dsty) {
                while (y != dsty) {
                    res += 'L';
                    y --;
                }
            }

            if (x > dstx) {
                while (x != dstx) {
                    res += 'U';
                    x --;
                }
            }

            if (x < dstx) {
                while (x != dstx) {
                    res += 'D';
                    x ++;
                }
            }

            if (y < dsty) {
                while (y != dsty) {
                    res += 'R';
                    y ++;
                }
            }
            res += '!';
        }
        return res;
    }
};