
#include <vector>
#include <string>

using namespace std;

/*
 * 挺有意思的一道题目，给定一个仅包含大写字母的字符串 s 以及一个操作次数 k，每次操作时可将 s 中的某一个字母变成其它大写字母
 * 问在最多操作 k 次的情况下，相同字母所组成的最长重复子串是多少。
 * 
 * 如果去除操作次数 k 的限制的话，对于一个字符串 s 而言，若将其变成重复字符串的话，就是字符串长度减去出现次数最多的字符个数
 * 例如 BABBBB，最小操作次数就是 6 - 5 = 1，也就是将前面的 A 替换成 B 即可。用代码表示就是 length - maxRepeatedTimes
 * 
 * 那么加上 k 这个限制之后，也就是 subLength - subMaxRepeatedTimes <= k，subLength 其实就是一个窗口，subMaxRepeatedTimes 就是该窗口中出现次数最多的字符次数。
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxTimes = 0, result = 0;

        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'A'] ++;
            maxTimes = max(maxTimes, count[s[i] - 'A']);

            while (i - left + 1 - maxTimes > k) {
                count[s[left] - 'A'] --;
                left ++;
            }

            result = max(result, i - left + 1);
        }
        return result;
    }
};
