#include <string>
#include <unordered_map>

using namespace std;

/*
 * 求 s 中包含 t 的最短子字符串，如 s = "ADOBECODEBANC", t = "ABC", 结果为 "BANC"
 * 
 * 1 <= s.length, t.length <= 10^5，也就是说，O(n^2) 时间复杂度的算法一定会超时
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq, sFreq;

        for (int i = 0; i < t.size(); i++)
            tFreq[t[i]] ++;
        
        int sCnt = 0;
        int startIndex = -1;
        int minLen = s.size() + 1;
        int left = 0, right = -1;

        while (left <= s.size() -1) {
            if (right + 1 < s.size() && sCnt < t.size()) {
                // 此时我们需要扩大窗口
                sFreq[s[right+1]] ++;

                if (sFreq[s[right+1]] <= tFreq[s[right+1]]) sCnt ++;

                right ++;
            }else {
                // 此时我们需要收缩窗口

                if (sCnt == t.size() && right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                sFreq[s[left]] --;

                if (sFreq[s[left]] < tFreq[s[left]]) sCnt --;

                left ++;
            }
        }

        if (startIndex != -1) return s.substr(startIndex, minLen);
        return "";
    }
};
