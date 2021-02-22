
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
 * 怎么说呢，有点儿麻烦的难度为 Easy 的问题。
 */
class Solution {
private:
    bool compare(const string& word1, const string& word2, unordered_map<char, int>& dictionary) {
        int p1 = 0, p2 = 0, n1 = word1.size(), n2 = word2.size();
        while (p1 < n1 || p2 < n2) {
            if (p1 >= n1) return true;
            else if (p2 >= n2) return false;
            else if (dictionary[word1[p1]] < dictionary[word2[p2]]) return true;
            else if (dictionary[word1[p1]] == dictionary[word2[p2]]) {p1 ++, p2 ++;}
            else return false;
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dictionary;
        for (int i = 0; i < order.size(); i++) dictionary[order[i]] = i;
        
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i+1], dictionary)) return false;
        }
        return true;
    }
};