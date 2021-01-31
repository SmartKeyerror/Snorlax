
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    // for any of k, checkPartitioning should be works.
    // just the same as 1278. Palindrome Partitioning III
    // https://leetcode.com/problems/palindrome-partitioning-iii/
    bool checkPartitioning(string s, int k = 3) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(k, n));

        for (int i = 0; i < 2 * n; i++) {
            for (int left = i / 2, right = (i + 1) / 2, cost = 0; left >= 0 && right < n; left--, right++) {
                if (s[left] != s[right]) 
                    cost++;

                if (left == 0) 
                    dp[right][0] = cost;

                else {
                    for (int j = 1; j < k; j++)
                        dp[right][j] = min(dp[right][j], dp[left - 1][j - 1] + cost);
                }
            }
        }
        
        // for 1278. Palindrome Partitioning III, we return dp[n-1][k-1]. In this problem, we need return it's cost whether equals to zero.
        return dp[n-1][k-1] == 0;
    }
};