
#include <vector>
#include <string>

using namespace std;

/*
 * 标准的正则匹配问题， 其中 '.' 匹配任意一个字符，'*' 匹配 0 个或多个前一个字符
 * 
 * 
 * 如果只有 '.' 这一个通配符的话，那么我们遍历一遍 s 和 p 即可:
 *  if (s[i] == p[i] || p[i] == '.')
 * 
 * 但是现在多了一个 '*'，我们得分情况讨论了。因为 '*' 可以匹配 0 次或者是多次，那么这不就是个选择吗
 * 选择一种匹配方式然后往下走，走不动了再回来。
 * - 匹配 0 次，例如 s = "abc", p = "*xabc"， s 保持不变，p 去掉 *x 后继续匹配
 * - 匹配多次，例如 s = "aabc", p = "a*bc"， 如果 s 和 p 的首字符相同的话，那么我们保持 p 不变，s 去掉一个字符，然后匹配
 *   此时 s = "abc"，p = "a*bc"
 */
class Solution {
    bool backtracking(string s, string p) {
        if (p.empty()) return s.empty();

        bool firstMatched = !s.empty() && (s[0] == p[0] || p[0] == '.');

        // 遇到了通配符 '*'，按照上述讨论的情况往下走
        if (p.size() >= 2 && p[1] == '*') {
            return backtracking(s, p.substr(2)) || (firstMatched && backtracking(s.substr(1), p));
        }
        else if (firstMatched)
            return backtracking(s.substr(1), p.substr(1));
        else
            return false;
    }
public:
    bool isMatch(string s, string p) {
        return backtracking(s, p);
    }
};
