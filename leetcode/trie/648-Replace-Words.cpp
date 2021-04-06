
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class TrieNode {
public:
    unordered_map<char, TrieNode *> next;
    bool is_word;
    TrieNode(bool flag = false) : is_word(flag) {};
};


class Trie {
private:
    TrieNode *dummyRoot;
public:
    Trie() : dummyRoot(new TrieNode()) {};

    void insertWord(string s) {
        TrieNode *current = dummyRoot;
        for (auto c : s) {
            if (current->next.count(c) == 0)
                current->next[c] = new TrieNode();
            current = current->next[c];
        }
        if (!current->is_word) current->is_word = true;
        return;
    }

    string findLongestPrefix(string s) {
        TrieNode *current = dummyRoot;
        for (int i = 0; i < s.size(); i++) {
            if (current->is_word) return s.substr(0, i);

            else if (current->next.count(s[i]) == 0)
                return "";
            
            current = current->next[s[i]];
        }
        return "";
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        string res = "";

        for (auto s : dictionary) trie.insertWord(s);

        vector<string> words;
        string temp;

        stringstream input(sentence);

        while(input>>temp) words.push_back(temp);

        for (auto s : words) {
            string findRes = trie.findLongestPrefix(s);

            if (s == "") res += s;
            else res += findRes;

            res += " ";
        }
        res.pop_back();
        return res;
    }
};