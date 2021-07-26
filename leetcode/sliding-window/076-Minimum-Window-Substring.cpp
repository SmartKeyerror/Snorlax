#include <string>
#include <unordered_map>

using namespace std;

/*
 * 求 s 中包含 t 的最短子字符串，如 s = "ADOBECODEBANC", t = "ABC", 结果为 "BANC"
 * 
 * 1 <= s.length, t.length <= 10^5，也就是说，O(n^2) 时间复杂度的算法一定会超时。
 */
class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();

        unordered_map<char, int> shash;
        unordered_map<char, int> thash;

        // 构字符串 t 的哈希表
        for (auto c : t) thash[c] ++;
        // 判断相等的依据
        int items = thash.size();

        int left = 0;
        
        // 当前有多少字符已经相同
        int equals = 0;

        // 结果保存，start 用于保存最终子串的起始位置，result 则是最短子串的长度
        int start = n + 1, result = n + 1;

        for (int right = 0; right < n; right++) {
            // 将 s[right] 纳入区间
            shash[s[right]] ++;

            if (shash[s[right]] == thash[s[right]]) {
                equals ++;
            }

            // 若区间满足题目要求，那么我们需要主动的减少这个区间
            while (equals >= items) {
                // 判断是否更短
                if (right - left + 1 < result) {
                    start = left;
                    result = right - left + 1;
                }
                // 需要将 s[left] 移除，注意在移除以前判断下 shash[s[left]] 和 thash[s[left]] 是否相同
                if (shash[s[left]] == thash[s[left]]) {
                    equals --;
                }
                shash[s[left]] --;
                left ++;
            }
        }
        return start == n+1 ? "" : s.substr(start, result);
    }
};
