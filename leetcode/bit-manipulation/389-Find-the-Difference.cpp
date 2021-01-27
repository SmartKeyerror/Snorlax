
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sa(26, 0), ta(26, 0);

        for (int i = 0; i < s.size(); i++) {
            sa[s[i] - 'a'] ++, ta[t[i] - 'a'] ++;
        }
        ta[t[t.size() - 1] - 'a'] ++;

        for (int i = 0; i < sa.size(); i++) {
            if (sa[i] != ta[i]) return i + 'a';
        }
        return 'a';
    }
};