
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        int mode = 1e9 + 7;
        vector<vector<long>> dp(n, vector<long>(5, 0));
        unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

        // init
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;

        for (int i = 1; i < n; i++) {
            for (auto vowel : vowels) {
                int j = vowel.second;
                switch (vowel.first) {
                case 'a':
                    dp[i][j] += dp[i-1][vowels['e']] % mode;
                    dp[i][j] += dp[i-1][vowels['u']] % mode;
                    dp[i][j] += dp[i-1][vowels['i']] % mode;
                    break;
                case 'e':
                    dp[i][j] += dp[i-1][vowels['a']] % mode;
                    dp[i][j] += dp[i-1][vowels['i']] % mode;
                    break;
                case 'i':
                    dp[i][j] += dp[i-1][vowels['e']] % mode;
                    dp[i][j] += dp[i-1][vowels['o']] % mode;
                    break;
                case 'o':
                    dp[i][j] += dp[i-1][vowels['i']] % mode;
                    break;
                case 'u':
                    dp[i][j] += dp[i-1][vowels['i']] % mode;
                    dp[i][j] += dp[i-1][vowels['o']] % mode;
                    break;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < 5; i++)
            res += dp[n-1][i] % mode;
        return res % mode;
    }
};