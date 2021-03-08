
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

/*
 * 最开始以为是有什么特别的技巧，但是想了半天似乎也只能使用暴力求解的方式，求出字符串 s 的所有子串，然后挨个儿进行频次统计
 * 
 * 夭寿了，O(n^3) 的 solution 都能在 Leetcode AC。
 */
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), result = 0;

        for (int i = 0; i < n - 2; i++) {

            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]] ++;

                int cmin = INT_MAX, cmax = 0;
                for (auto item : freq) {
                    cmin = min(cmin, item.second);
                    cmax = max(cmax, item.second);
                }
                result += cmax - cmin;
            }
        }
        return result;
    }
};

