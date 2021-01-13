
#include <string>

using namespace std;

/*
 * Given a binary string s (a string consisting only of '0' and '1's). Return the number of substrings with all characters 1's.
 * 
 * 翻译渣渣，所以就不再翻译了。可以认为是一个排列组合问题，对于 `1111` 来说，其全部包含 `1` 的子串个数为 (4 * 5) / 2，也就是 n * (n + 1) / 2，Hint 中也给出了提示。
 * 
 * 那么现在的问题就变成了 s 字符串中一共有多少组全部由 `1` 所组成的区域? 每个区域中 `1` 的个数是多少?
 * 
 * 例如 "0110111" 共有两个连续的区域，"11" 和 "111"，那么第一个区域的子串个数为 2 * 3 / 2 = 3，第二个区域的子串个数为 3 * 4 / 2 = 6，两者相加为 9。
 */
class Solution {
public:
    int numSub(string s) {
        long res = 0, k = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') k ++;
            else {
                res += k * (k + 1) / 2;
                k = 0;
            }
        }
        if (k) res += k * (k + 1) / 2;

        return res % 1000000007;
    }
};
