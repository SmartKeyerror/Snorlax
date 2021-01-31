#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 成分组成问题，统计 s 中每个单词出现的频次然后遍历 t 计算绝对距离即可
 * s and t contain lower-case English letters only.
 */
class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26];
        memset(freq, 0, sizeof(freq));

        for (char c : s) freq[c - 'a'] ++;
        for (char c : t) freq[c - 'a'] --;

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) res += freq[i];
        }
        
        return res;
    }
};
