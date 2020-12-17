
#include <vector>

using namespace std;

class Solution {
public:

    // 对每一行进行 flip and invert
    void flipAndInvertARow(vector<int> &row) {
        int i = 0, j = row.size() - 1;
        while (i <= j) {
            int temp = row[i];
            row[i] = 1 - row[j];
            row[j] = 1 - temp;
            i ++, j --;
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++)
            flipAndInvertARow(A[i]);
        return A;
    }
};
