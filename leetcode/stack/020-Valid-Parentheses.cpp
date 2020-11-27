#include <string>
#include <stack>
#include <map>

using namespace std;

/*
 * 经典的括号匹配问题, 同时也是栈结构最为经典的使用场景之一。s 中所包含括号为: '()[]{}'
 * 思路非常简单，从头到尾遍历字符串，遇到左括号('('、'['，'{')时入栈，遇到右括号时比较当前栈顶与该右括号是否匹配
 * 若匹配，则从栈中弹出匹配的左括号，继续访问 s 下一个字符，若不匹配，直接返回 false
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.size() <= 1) return false;

        stack<char> parenthesStack;
        map<char, char> parenthesMap = {{'(',')'}, {'[', ']'}, {'{', '}'}};

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                parenthesStack.push(s[i]);
            else {
                if (parenthesStack.empty()) return false;
                char topValue = parenthesStack.top();
                if (s[i] != parenthesMap[topValue])
                    return false;
                parenthesStack.pop();
            }
        }
        return parenthesStack.empty();
    }
};
