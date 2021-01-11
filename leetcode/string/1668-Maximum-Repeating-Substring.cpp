
#include <string>

using namespace std;


class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int result = 0, m = sequence.size(), n = word.size();

        for (int i = 0; i < m - n + 1; i++) {
            int j = i, k = 0, current = 0;
            while (j < m) {
                if (sequence[j] == word[k]) j++, k++;
                else break;
                if (k == n) current ++, k = 0;
            }
            result = max(result, current);
        }
        return result;
    }
};
