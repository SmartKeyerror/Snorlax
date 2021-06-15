
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        if (n <= 1) return true;

        unordered_map<char, int> freq;

        for (const auto &word : words) {
            for (const auto c : word) {
                freq[c] ++;
            }
        }

        for (const auto &item : freq) {
            if (item.second % n != 0) {
                return false;
            }
        }

        return true;
    }
};