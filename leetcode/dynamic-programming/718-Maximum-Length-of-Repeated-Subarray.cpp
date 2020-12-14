#include <vector>

using namespace std;

/*
 * 求两个数组最长的相同子数组(不是子序列)
 *  A: [1, 2, 3, 4, 5, 6]
 *  B: [7, 8, 9, 1, 2, 3, 4]
 * 结果为 4，相同的子数组为 [1, 2, 3, 4]
 * 
 * DP解法: memory[i][j] 表示以 A[i]、A[j] 结尾的最长相同子数组长度，那么如果 A[i] == A[j] 的话， 那么 
 * memory[i][j] = memory[i-1][j-1] + 1， 然后处理一下边界条件即可。
 */
class Solution {
private:
    int dpSolution(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), res = 0;
        vector<vector<int>> memory(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0)
                        memory[i][j] = 1;
                    else
                        memory[i][j] = memory[i-1][j-1] + 1;
                }   res = max(res, memory[i][j]);
            }
        }
        return res;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        return dpSolution(A, B);
    }
};
