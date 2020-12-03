#include <string>

using namespace std;


class Solution {
private:

    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
    // Memory Usage: 6.7 MB, less than 63.71% of C++ online submissions for Is Subsequence.
    // 喵喵喵? 这特喵的也行??
    bool brouteSolution(string s, string t) {
        int pos = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = pos; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    pos = j + 1;
                    count ++;
                    break;
                }
            }
        }
        if (count == s.size()) 
            return true;
        return false;
    }
public:
    bool isSubsequence(string s, string t) {
       return brouteSolution(s, t);
    }
};