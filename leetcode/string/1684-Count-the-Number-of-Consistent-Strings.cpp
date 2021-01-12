
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> pool;
        for (char c : allowed) pool.insert(c);

        int result = words.size();
        for (string word : words) {
            for (int i = 0; i < word.size(); i++) {
                if (pool.count(word[i]) == 0) {
                    result --;
                    break;
                }
            }
        }
        return result;
    }
};