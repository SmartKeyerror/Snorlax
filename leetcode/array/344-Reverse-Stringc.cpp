
#include <vector>

using namespace std;

/*
 * 原地reverse数组，对撞指针逐一交换即可
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 0) return;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i ++, j --;
        }
    }
};
