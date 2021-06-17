
#include <vector>

using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size(), result = 0;

        int current;

        for (int i = 0; i < m; i++) {
            current = 0;
            for (int j = 0; j < n; j++) {
                current += accounts[i][j];
            }
            result = max(result, current);
        }
        return result;
    }
};
