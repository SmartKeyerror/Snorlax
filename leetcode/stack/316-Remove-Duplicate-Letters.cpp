
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;


/*
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 输入：s = "bcabc"
 * 输出："abc
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 */
class Solution {
public:
    // 时空复杂度均为 O(n)
    // 优化: 可以使用 vector 来替换 unordered_map 和 unordered_set，使用 stirng 来模拟栈
    string removeDuplicateLetters(string& s) {
        // 首先先统计每一个字符出现的频率，可以使用 vector，也可以用 hashmap
        unordered_map<char, int> freq;
        for (auto c : s) freq[c]++;

        unordered_set<int> visited;

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char current = s[i];

            freq[current]--;

            if (visited.count(current) != 0) continue;

            // 不满足栈顶到栈底单调递减
            while (!st.empty() && current < st.top()) {
                if (freq[st.top()] == 0) break;
                else {
                    visited.erase(st.top());
                    st.pop();
                }
            }

            st.push(current);
            visited.insert(current);
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};