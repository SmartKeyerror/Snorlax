
#include <string>
#include <vector>
#include <cmath>

using namespace std;


/*
 * 感觉是一道挺有意思的题目，但是不知道为什么会有 5424 个 Down Vote，😃
 * 
 * 将给定的字符串 s 变成一个从左到右、从上到下的 "之" 字型图像，然后返回逐行所拼接的字符串。
 * 
 * 如 "PAYPALISHIRING"，当 numRows = 4 时，其 "之" 字形图像为:
 * 
 *  P     I    N
 *  A   L S  I G
 *  Y A   H R
 *  P     I
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res = "";
        int c = (numRows-1)*2;
        for (int j = 0; j < numRows; j++) {
            for (int i = 0; i < s.length(); i++) {
                if (i % c == j || i % c == c - j) res += s[i];
            }
        }
        return res;
    }
};