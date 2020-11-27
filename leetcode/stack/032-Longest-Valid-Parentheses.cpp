
#include <string>
#include <stack>

using namespace std;

/*
 * 求字符串 s 中最长的有效括号长度，如 ")()())" 的最长有效括号字串为 "()()"，长度为 4.
 * 
 * 这道题依然可以借助栈实现，遇到左括号时入栈，遇到右括号时与栈顶元素尝试匹配，匹配成功则弹出，并更新结果值，继续查看下一个括号
 * 由于我们要求的是最长有效括号，所以栈中不再存储括号字符，而是存储当前括号所在的索引，并且还需要一个记录有效括号串的起始位置
 * 
 * - 情况1: 遇到 '('，那么我们直接入栈，不更新 start
 * - 情况2: 遇到 ')'，若此时栈为空，更新 start，使其右移一位。
 *         若此时栈不为空，直接弹出当前栈顶元素，因为栈里面一定只有 '('，所以一定是匹配的。弹出栈顶元素之后又可分为栈为空和栈不为空:
 *           - 栈为空: 当前 s[i] 之前的括号完全匹配, 此时子串长度为 i - start + 1
 *           - 栈不为空: 那么此时只能认为只有 i - stack.top() 这么长的串为有效串
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, start = 0;
        
        stack<int> indexStack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                indexStack.push(i);
            else {
                if (indexStack.empty())
                    start = i + 1;
                else {
                    indexStack.pop();
                    if (indexStack.empty())
                        result = max(result, i - start + 1);
                    else
                        result = max(result, i - indexStack.top());
                }
            }
        }
        return result;
    }
};
