
#include <string>
#include <stack>

using namespace std;

/*
 * 括号匹配问题，与一般的括号匹配问题不同的是，s 中包含了 '*' 通配符，可以代替 '('，')' 或者什么都不表示
 * 
 * 首先考虑回溯法，剪枝条件不好处理，并且记录括号的栈会动态变更，所以 Pass。
 * 
 * 再考虑栈实现，我们可以这样来做: 使用两个栈，一个记录 '('，当遇到 ')' 时 pop 栈顶；另一个栈用来保存 '*' ，用来“救火”。
 */
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftPar, wildcard;

        for (int i = 0; i < s.size(); i++) {
            int current = s[i];
            if (current == '(') leftPar.push(i);
            else if (current == '*') wildcard.push(i);
            else {
                if (!leftPar.empty()) leftPar.pop();            // 自己能匹配 ')'
                else if (!wildcard.empty()) wildcard.pop();     // 自己匹配不了，通配符来凑一个 '(' 进行匹配
                else return false;
            }
        }

        // 假设 s = "(*"，那么此时 leftPar 中存在一个 '('，wildcard 中存在一个 '*'
        // * 的位置必须要出现在 '(' 的左边儿，因为此时不能再有更多的 '(' 了，'*' 只能表示 ')'
        while (!leftPar.empty() && !wildcard.empty()) {
            if (leftPar.top() > wildcard.top()) return false;
            leftPar.pop(), wildcard.pop();
        }
        return leftPar.empty();
    }
};