
#include <string>
#include <unordered_map>

using namespace std;


class Trie {
private:
    class TreeNode {
        public:
            bool isWord;
            unordered_map<char, TreeNode *> next;
            TreeNode() {
                isWord = false;
            }
    };
    int size;
    TreeNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        size = 0;
        root = new TreeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next.count(word[i]) == 0)
                current->next.insert({word[i], new TreeNode()});
            current = current->next[word[i]];
        }
        if (!current->isWord) {
            size ++;
            current->isWord = true;
        }
        return ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next.count(word[i]) == 0)
                return false;
            current = current->next[word[i]];
        }
        return current->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *current = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (current->next.count(prefix[i]) == 0)
                return false;
            current = current->next[prefix[i]];
        }
        return true;
    }
};
