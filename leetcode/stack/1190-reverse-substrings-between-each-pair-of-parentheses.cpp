
#include <string>
#include <stack>

using namespace std;

/*
 * 给出一个字符串 s（仅含有小写英文字母和括号）。
 * 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
 * 注意，您的结果中 不应 包含任何括号。
 * 
 * 输入：s = "(u(love)i)"
 * 输出："iloveu"
 * 
 * 输入：s = "(ed(et(oc))el)"
 * 输出："leetcode"
 * 
 * 首先模拟程序的运行，以 s = "(u(love)i)" 为例，从头到尾遍历，发现第一个右括号时，需要和最后出现的左括号进行匹配，此时我们应该将括号之间的内容反转:
 * 
 * 得到 (uevoli)，然后继续遍历，发现第二个右括号时和最后一个出现的左括号进行匹配，并反转括号中间的字符，得到 iloveu
 * 
 * 因此，使用一个栈来保存相关内容
 */
class Solution {
public:
    string reverseParentheses(string s) {
        if (s.size() == 0) return s;

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] != ')') {
                // 直接压栈即可
                st.push(s[i]);
            }
            else {
                // 那么此时我们就需要找到 (xxxxx 这样的子串
                string temp = "";
                while (st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for (auto c : temp) st.push(c);
            }
        }

        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};