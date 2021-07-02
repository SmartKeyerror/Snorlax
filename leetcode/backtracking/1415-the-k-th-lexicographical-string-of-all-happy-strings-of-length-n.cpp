
#include <vector>
#include <string>

using namespace std;


/*
 * 一个 「开心字符串」定义为：
 * 仅包含小写字母 ['a', 'b', 'c'].
 * 对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
 * 比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。
 * 
 * 给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。
 * 
 * 请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串 。
 * 
 * 输入：n = 1, k = 3
 * 输出："c"
 * 解释：列表 ["a", "b", "c"] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 "c" 。
 * 
 * 1 <= n <= 10
 * 1 <= k <= 100
 * 
 * 回溯取长度为 n 的所有开心字符串，排序，再取第 K 个。
 */
class Solution {
private:
    vector<char> choices;

    vector<string> result;

    void backtracking(int n, string& s) {

        // 终止条件
        if (s.size() == n) {
            result.push_back(s);
            return;
        }

        for (int i = 0; i < choices.size(); i++) {
            if (s.size() == 0 || s.back() != choices[i]) {
                s.push_back(choices[i]);
                backtracking(n, s);
                s.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        choices = {'a', 'b', 'c'};

        string s = "";
        backtracking(n, s);

        if (result.size() < k) return "";

        sort(result.begin(), result.end());

        return result[k-1];
    }
};