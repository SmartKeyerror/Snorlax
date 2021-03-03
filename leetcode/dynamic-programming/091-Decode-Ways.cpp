
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 0 || s[0] == '0') return 0;

        // dp[i] 表示以第 i 个元素为结尾的 s[0...i] 共有多少种解码方式
        vector<int> dp(n, 0);

        dp[0] = 1;

        if (n > 1 && (s[0] - '0') * 10 + (s[1] - '0') <= 26) dp[1] = 1;

        if (n > 1 && s[1] != '0') dp[1] += 1;

        for (int i = 2; i < n; i++) {

            if (s[i] != '0') dp[i] += dp[i-1];
            
            int a = (s[i-1] - '0') * 10 + (s[i] - '0');

            if (a >= 10 && a <= 26) dp[i] += dp[i-2];
        }

        return dp[n];
    }
};