
#include <string>
#include <vector>

using namespace std;

/*
 * 求 n 个字符串的最长公共前缀
 * 
 * 0 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * 
 * 这一看就符合暴力解法的条件，O(n^2) 最大操作数值也才 40000
 * 
 */
class Solution {

    // Runtime: 4 ms, faster than 94.57% of C++ online submissions for Longest Common Prefix.
    // Memory Usage: 9.4 MB, less than 79.81% of C++ online submissions for Longest Common Prefix.
    // WTF? 暴力解法比 94.57% 的解法还快???
    string brouteForce(vector<string>& strs) {

        if (strs.size() == 0) return "";
        if (strs.size() ==1) return strs[0];

        int prefixLen = 0;

        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 0; j < strs.size() - 1; j++) {
                if (strs[j][i] != strs[j+1][i]) 
                    return strs[0].substr(0, prefixLen);
            }
            prefixLen ++;
        }
        return strs[0].substr(0, prefixLen);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        return brouteForce(strs);
    }
};