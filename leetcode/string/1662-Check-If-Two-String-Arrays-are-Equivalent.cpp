
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";

        for (string word : word1) s1 += word;
        for (string word : word2) s2 += word;

        // A string is represented by an array if the array elements concatenated in order forms the string.
        // 如果说 word2 的可以不按照顺序进行组合的话，那就需要进行排序。
        // sort(s1.begin(), s1.end()), sort(s2.begin(), s2.end());

        return s1 == s2;
    }
};