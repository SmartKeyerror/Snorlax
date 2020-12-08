#include <string>
#include <unordered_map>

using namespace std;

class WordDictionary {
private:
        class TreeNode {
        public:
            bool isWord;
            unordered_map<char, TreeNode *> next;
            TreeNode() {
                isWord = false;
            }
    };
    TreeNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode *current = root;
        for (int i = 0; i < word.size(); i++) {
            if (current->next.count(word[i]) == 0)
                current->next.insert({word[i], new TreeNode()});
            current = current->next[word[i]];
        }
        current->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }

    bool dfs(string &word, TreeNode *node, int index) {
        if (index == word.size())
            return node->isWord;
        
        if (word[index] != '.') {
            if (node->next.count(word[index]) == 0)
                return false;
            return dfs(word, node->next[word[index]], index + 1);
        } else {
            // 多叉树的遍历
            for (auto &item: node->next) {
                if (dfs(word, node->next[item.first], index + 1))
                    return true;
            }
        }
        return false;
    }
};
