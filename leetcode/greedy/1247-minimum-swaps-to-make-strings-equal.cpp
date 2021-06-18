
#include <string>

using namespace std;


class Solution {
public:
    int minimumSwap(string& s1, string& s2) {
        int x = 0, y = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                s1[i] == 'x' ? x++ : y++;
            }
        }

        int diff = x + y;

        if (diff % 2) return -1;

        return x % 2 == 0 ? diff / 2 : diff / 2 + 1;
    }
};