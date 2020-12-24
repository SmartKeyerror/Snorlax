
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows == 0) return result;

        result.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> inner;
            inner.push_back(1);
            for (int j = 0; j < result[i-1].size() - 1; j++) {
                inner.push_back(result[i-1][j] + result[i-1][j+1]);
            }
            inner.push_back(1);
            result.push_back(inner);
        }
        return result;
    }
public:
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex).back();
    }
};