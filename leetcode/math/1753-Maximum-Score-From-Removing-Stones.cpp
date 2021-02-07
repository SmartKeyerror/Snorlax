
#include <algorithm>

using namespace std;

class Solution {

    int res;

    void recursve(int a, int b, int c) {
        if (a == 0 && b == 0 || a == 0 && c == 0 || b == 0 && c == 0) return;

        if (a == 0) {
            res += min(b, c);
            return;
        }

        if (b == 0) {
            res += min(a, c);
            return;
        }

        if (c == 0) {
            res += min(a, b);
            return;
        }

        int minStone = min(a, min(b, c));
        int maxStone = max(a, max(b, c));
        int rest = a + b + c - minStone - maxStone;

        res ++;
        recursve(minStone - 1, maxStone - 1, res);

    }
public:
    int maximumScore(int a, int b, int c) {
        res = 0;
        recursve(a, b, c);
        return res;
    }
};