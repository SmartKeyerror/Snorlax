
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string& s) {

        int result = 0;

        int n = s.size();
        if (n <= 1) return 0;

        stack<int> st;

        int posi = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                // 此时 s[i] 为 ')'，并且栈为空
                if (st.empty()) {
                    posi = i + 1;
                    continue;
                } else {
                    // 计算最长合法子串长度
                    st.pop();
                    if (st.empty()) {
                        result = max(result, i - posi + 1);
                    } else {
                        // (())
                        // ↑
                        // posi
                        result = max(result, i - st.top());
                    }
                }
            }
        }
        return result;
    }
};