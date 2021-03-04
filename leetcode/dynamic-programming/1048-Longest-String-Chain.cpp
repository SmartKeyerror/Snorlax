
#include <vector>
#include <string>

using namespace std;

/*
 * 问题的本质在于如何快速判断 word1 是否是 word2 的 predecessor，也就是先驱。
 * 
 * 首先，len(word2) - len(word1) 必然为 1，否则 word1 必然不能够添加任意字符得到 word2。
 * 
 * 然后，我们可以判断 delete word2 中的某个字符之后是否与 word1 相等来判断 word1 是否为 word2 的先驱。
 */
class Solution {
public:

    // // 判断 word1 是否为 word2 的先驱
    bool isPredecessor(const string &a, const string &b) {
        int i = 0, j = 0, n1 = a.size(), n2 = b.size();
        if (n1 + 1 != n2) return false;
        for(; j != n2 && !(a[i] == b[j] && ++i == a.size()); ++j);
        return i == n1;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size(), result = 0;

        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};
