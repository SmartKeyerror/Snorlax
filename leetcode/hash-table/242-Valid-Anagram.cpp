
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 可用排序的方式解决，时间复杂度为 O(nlogn)
    // Runtime: 64 ms, faster than 23.37% of C++ online submissions for Valid Anagram.
    bool isAnagramSortSolution(string s, string t) {

        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // 另外就是将成分拆开，扔到一个 map 里面，逐一遍历
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;

        unordered_map<char, int> record;

        for (int i = 0; i < s.size(); i++)
            record[s[i]] ++;
        
        for (int i = 0; i < t.size(); i++) {
            if (record.find(t[i]) == record.end() || record[t[i]] == 0)
                return false;
            else
                record[t[i]] --;
        }
        return true;
    }
};