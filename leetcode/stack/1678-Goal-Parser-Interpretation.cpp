
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    string interpret(string command) {
        string res = "";
        stack<char> st;

        for (auto c : command) {
            if (c == 'G') res += c;
            else if (c == ')') {
                if (st.top() != '(') {
                    while (st.size() > 0)
                        st.pop();
                    res += "al";
                }
                else {
                    st.pop();
                    res += 'o';
                }
            }
            else st.push(c);
        }
        return res;
    }
};