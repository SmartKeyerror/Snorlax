
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
private:
    unordered_set<char> pool = {'a', 'e', 'i', 'o', 'u'};
public:
    int maxVowels(string s, int k) {
        int result = 0, current = 0;

        for (int i = 0; i < k; i++) {
            if (pool.count(s[i])) current ++;
        }

        result = current;

        for (int i = 1; i < s.size() - k + 1; i++) {
            if (pool.count(s[i-1])) current --;
            if (pool.count(s[i+k-1])) current ++;
            result = max(result, current);
        }

        return result;
    }
};