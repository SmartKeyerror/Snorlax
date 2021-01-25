
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> freq(A.size(), vector<int>(26, 0));

        for(int i = 0; i < A.size(); ++i) {
            for(char c : A[i]) {
                freq[i][c - 'a'] += 1;
            }
        }

        vector<string> res;
        for(int i = 0; i < 26; ++i) {
            int temp = INT_MAX;
            for(int j = 0; j < A.size(); ++j) {
                temp = min(temp, freq[j][i]);
            }
            for(int k = 0; k < temp; ++k) {
                char t = 'a' + i;
                res.push_back(string(1,t));
            }
        }
        return res;
    }
};