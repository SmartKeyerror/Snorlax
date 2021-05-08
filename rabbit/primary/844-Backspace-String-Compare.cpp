
#include <stack>
#include <string>

using namespace std;


class Solution {
private:
    stack<char> getPureString(string& str) {
        stack<char> st;
        for (auto c : str) {
            if (c == '#') {
                if (!st.empty()) st.pop();
            }
            else st.push(c);
        }
        return st;
    }
public:
    bool backspaceCompare(string s, string t) {
        auto a = getPureString(s);
        auto b = getPureString(t);

        if (a.size() != b.size()) return false;

        while (!a.empty()) {
            char ca = a.top();
            char cb = b.top();

            if (ca != cb) return false;

            a.pop(), b.pop();
        }

        return true;
    }
};