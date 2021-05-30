
#include <string>

using namespace std;


class Solution {
public:
    int getRes(string& s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            res = res * 10 + (c - 'a');
        }
        return res;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getRes(firstWord) + getRes(secondWord) == getRes(targetWord);
    }
};
