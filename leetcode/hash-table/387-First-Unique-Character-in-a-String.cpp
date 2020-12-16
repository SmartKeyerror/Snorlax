
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 寻找字符串 s 中第一个没有重复的字符索引，例如 "loveleetcode"，第一个没有重复的字符为 'v'，索引为 2，故返回 2。
 * 相当简单的一道问题，把 s 中的频率计算一遍，找出频率为 1 的那个字符即可。
 * 
 * hashmap 和 vector 都能做，下面是效率的一个基本对比:
 */
class Solution {
private:
    // Runtime: 88 ms, faster than 42.13% of C++ online submissions for First Unique Character in a String.
    int hashmapSolutin(string &s) {
        if (s.size() == 0) return -1;

        unordered_map<char, int> frequency;
        for (char c: s)
            frequency[c] ++;
        
        for (int i = 0; i < s.size(); i++)
            if (frequency[s[i]] == 1)
                return i;
        
        return -1;
    }

    // Runtime: 24 ms, faster than 88.87% of C++ online submissions for First Unique Character in a String.
    int arraySolution(string &s) {
        if (s.size() == 0) return -1;

        vector<int> frequency(26, 0);
        for (char c: s)
            frequency[c - 'a'] ++;
        
        for (int i = 0; i < s.size(); i++)
            if (frequency[s[i] - 'a'] == 1)
                return i;
            
        return -1;
    }
public:
    int firstUniqChar(string s) {
        return arraySolution(s);
    }
};
