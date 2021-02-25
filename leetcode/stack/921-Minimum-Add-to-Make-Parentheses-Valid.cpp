
#include <string>
#include <stack>

using namespace std;

/*
 * 和验证括号是否完全匹配问题一样，采用栈解决，只不过在这一道题中当遇到了不匹配的括号时，我们需要主动地让其匹配，也就是添加一个括号，添加操作计入最终的结果中。
 * 
 * 本质上来说这应该是一道 Easy 难度的问题。
 */
class Solution {
public:
    int minAddToMakeValid(string S) {
        int n = S.size(), result = 0;
        stack<char> pstack;

        for (int i = 0; i < n; i++) {
            char current = S[i];
            if (current == '(') pstack.push(current);       // 左括号无脑入栈
            else {
                if (pstack.empty()) {                       // 此时没有与之匹配的 '('，所以 result++
                    result ++;
                    continue;
                } else                                      // 存在匹配的 '('，让匹配的 '()' 一边儿凉快去
                    pstack.pop();
            }
        }
        result += pstack.size();
        return result;
    }
};