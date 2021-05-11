
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


// 判断两个字符串是否是 Anagram， 方法有很多。比较直接的两个办法就是排序和使用 hashmap。
/*
 * 判断两个字符串是否是 Anagram， 方法有很多。比较直接的两个办法就是排序和使用 hashmap。
 * 前者时间复杂度为 O(nlogn)，空间复杂度 O(1)；后者时间复杂度 O(n)，空间复杂度 O(n)。
 */
class Solution {
private:
    // Runtime: 16 ms, faster than 27.34% of C++ online submissions for Valid Anagram.
    // Memory Usage: 7 MB, less than 99.79% of C++ online submissions for Valid Anagram.
    bool sortSolution(string& s, string& t) {
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }

    // Runtime: 12 ms, faster than 49.84% of C++ online submissions for Valid Anagram.
    // Memory Usage: 7.1 MB, less than 98.11% of C++ online submissions for Valid Anagram.
    bool hashmapSolution(string& s, string& t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> material;

        for (auto c : s) material[c] ++;

        for (auto c : t) {
            if (material.count(c) == 0) return false;
            material[c] --;
            if (material[c] == 0) material.erase(c);
        }
        return false;
    }

public:
    bool isAnagram(string& s, string& t) {
        // return sortSolution(s, t);
        return hashmapSolution(s, t);
    }
};