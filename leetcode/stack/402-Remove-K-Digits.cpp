
#include <string>

using namespace std;

/*
 * Given string num representing a non-negative integer num, and an integer k, 
 * return the smallest possible integer after removing k digits from num.
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 * 
 * 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
 * 
 * 相似题目: 
 * - 316. Remove Duplicate Letters
 * 
 * 移除 K 个数字，使得结果的字典序最小。字典序可以使用单调栈来保证，但是 K 个字符该怎么处理?
 * 
 * 我们可以维护一个 removed 变量，表示已经移除了多少个数字，这个变量只会在弹栈时更新。
 * 
 */

class Solution {
public:
    // 时间复杂度: O(n)，空间复杂度: O(n)
    string removeKdigits(string& num, int k) {
        int n = num.size(), removed = 0;

        if (n == k) return "0";

        string st = "";

        for (int i = 0; i < n; i++) {
            char current = num[i];

            while (!st.empty() && current < st.back() && removed != k) {
                st.pop_back();
                removed++;
            }

            if (st.size() != 0 || current != '0')
                st.push_back(current);
        }

        while (!st.empty() && removed != k) {
            st.pop_back();
            removed++;
        }

        return st == "" ? "0" : st;
    }
};