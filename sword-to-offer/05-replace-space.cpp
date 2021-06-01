/*
 *
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * 
 * 输入：s = "We are happy."
 * 输出："We%20are%20happy."
 * 
 * 实在没啥好说的，遍历一遍即可
 */

#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res = "";

        if (s.empty()) return res;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') res += "%20";
            else res += s[i];
        }

        return res;
    }
};
