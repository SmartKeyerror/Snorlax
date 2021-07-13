#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

/*
 * 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 *
 * 像删除给定字符串/数组的一些元素以后，使得删除后的结果字典序/数值最小的问题，都可以使用单调栈来进行思考。
 * 
 * 相似的题目包括:
 * - 402. Remove K Digits
 * - 316. Remove Duplicate Letters
 * - 321. Create Maximum Number
 * 
 * 对于这道题目而言，题目额外补充了两个要求: 
 * 1. 子序列必须包含 s 中所有的不同字符
 * 2. 且只包含 1 次
 * 
 * 我们可以用两个额外的容器来保存这部分的信息。
 * 
 * “只包含 1 次” 可以使用 visited 数组来完成，压栈时 visited[char] = true，弹出时则置为 false。
 * 
 * “子序列必须包含 s 中所有的不同字符”需要记录下当前元素之后，其余元素所出现的频率。如果当前元素在此之后出现的频次为 0 的话，那么是不能进行弹栈操作的。
 */
class Solution {
public:
    // 时空复杂度均为 O(n)
    string smallestSubsequence(string& s) {
        unordered_map<char, int> freq;

        for (auto c : s) freq[c]++;

        vector<bool> visited(26, false);

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char current = s[i];

            // 对于当前遍历到的元素来说，不管我们怎么处理，其频率都应该减少一个
            freq[current] --;

            if (visited[current - 'a']) continue;

            while (!st.empty() && s[i] < st.top()) {
                // 正常来讲这里需要弹栈，但是这道题需要进行额外的判断

                // 如果 st.top() 在后面儿都没有出现了的话，必然不能弹栈
                if (freq[st.top()] == 0) break;

                // 否则，进行弹栈操作
                else {
                    visited[st.top() - 'a'] = false;
                    st.pop();
                }
            }

            st.push(current);
            visited[current - 'a'] = true;
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};