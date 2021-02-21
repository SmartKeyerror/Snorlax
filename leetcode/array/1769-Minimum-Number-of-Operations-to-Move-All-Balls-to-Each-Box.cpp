

#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> result(n, 0);
        vector<int> pool;

        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') pool.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j : pool) {
                result[i] += abs(i - j);
            }
        }

        return result;
    }
};
