

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result = 0;

        auto sorted = heights;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) result ++;
        }

        return result;
    }
};