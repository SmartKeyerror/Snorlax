
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


/*
 * 判断 word1 和 word2 是否为 "close string"，即通过交换元素位置以及建立映射这两种方式操作 word1，使其结果等于 word2。
 * 
 * 题意本身很好理解，首先来看第一条规则: 可以任意交换 wrod1 的元素顺序。
 * 
 * 那么对于 "abc" 以及 "cab" 这两个字符串而言，组成它们的 "成分" 相同，也就是每一个字符出现的频率都相同，所以它们一定是 close string。
 * 
 * 再看第二条规则: 互换两个字符出现的频率。
 * 
 * 那么对于 "aab" 以及 "bba" 来说，前者 'a'、'b' 的频次分别为 2 和 1，而后者 'a'、'b' 的频次分别为 1 和 2，我们就可以调换 'a'、'b' 出现的频次使其变为 close string。
 */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        if (n1 != n2) return false;

        unordered_set<char> s1, s2;
        vector<int> freq1(26, 0), freq2(26, 0);


        for (auto c : word1) {
            freq1[c - 'a'] ++;
            s1.insert(c);
        }

        for (auto c : word2) {
            freq2[c - 'a'] ++;
            s1.insert(c);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return s1 == s2 && freq1 == freq2;
    }
};