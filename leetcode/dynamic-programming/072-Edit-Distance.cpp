
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

/*
 * 求 word1 变成 word2 的最短编辑距离，每次编辑可以进行插入、删除和替换操作，挺有意思的一道题目
 * 
 * 由于涉及到两个字符串，所以必然需要一个二维数组来进行递推
 * 假设 memory[i][j] 表示当 word1 长度为 i , word2 长度为 j 时，将 word1 转换成 word2 的最小编辑长度
 * 
 * 首先来看边界情况，也就是当 i == 0 或者是当 j == 0 的情况，此时编辑次数就是 j 或者是 i
 * - "" => "a", 结果为 1，插入一个 'a'
 * - "" => "ab"， 结果为 2,插入 'a' 和 'b'
 * - "a" => ""，结果为 1, 删除一个 'a'
 * - "ab" => "",结果为 2, 删除 'a' 和 'b'
 * 
 * 再来看递推关系式：
 * - 如果 word1[i-1] == word2[j-1] 的话，该处字符不用编辑，所以 memory[i][j] = memory[i-1][j-1]
 * - 如果 word1[i-1] != word2[j-1] 的话，需要分情况讨论:
 *   - 如果需要删除一个字符使得 word1[i-1] 与 word2[j-1] 相等的话，那么 memory[i][j] = memory[i-1][j] + 1
 *   - 如果需要替换一个字符使得 word1[i-1] 与 word2[j-1] 相等的话，那么 memory[i][j] = memory[i-1][j-1] + 1
 *   - 如果需要插入一个字符使得 word1[i-1] 与 word2[j-1] 相等的话，那么 memory[i][j] = memory[i][j-1] + 1
 * 
 * 可以看到，这就是二维平面中相邻节点间的关系
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> memory = vector<vector<int>>(n1+1, vector<int>(n2+1, INT_MAX));

        // 初始化边界条件
        memory[0][0] = 0;
        for (int i = 1; i <= n1; i++) memory[i][0] = memory[i-1][0] + 1;
        for (int j = 1; j <= n2; j++) memory[0][j] = memory[0][j-1] + 1;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1])
                    memory[i][j] = memory[i-1][j-1];
                else
                    memory[i][j] = min(min(memory[i-1][j-1], memory[i][j-1]), memory[i-1][j]) + 1;
            }
        }
        return memory[n1][n2];
    }
};
