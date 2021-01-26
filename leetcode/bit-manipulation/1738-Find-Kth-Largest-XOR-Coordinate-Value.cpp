
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> coordinates;
        vector<vector<int>> prefixXOR(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) prefixXOR[i][j] = matrix[0][0];
                else if (i == 0 && j != 0) prefixXOR[i][j] = prefixXOR[i][j-1] ^ matrix[i][j];
                else if (i != 0 && j == 0) prefixXOR[i][j] = prefixXOR[i-1][j] ^ matrix[i][j];
                else prefixXOR[i][j] = prefixXOR[i-1][j] ^ prefixXOR[i][j-1] ^ prefixXOR[i-1][j-1] ^ matrix[i][j];
            }
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (minHeap.size() == k) {
                    if (prefixXOR[i][j] > minHeap.top()) {
                        minHeap.pop();
                        minHeap.push(prefixXOR[i][j]);
                    }
                }
                else minHeap.push(prefixXOR[i][j]);
            }
        }

        return minHeap.top();
    }
};