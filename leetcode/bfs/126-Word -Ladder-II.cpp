#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/*
 * 126 号问题的进阶版，不再要求返回最短路径长度了，而是返回所有的最短路径。
 * 
 * 当我们找到了一个最短路径时，其余的相同长度的路径一定会在同一层被遍历到，参考二叉树的层序遍历。
 * 
 * 因此，我们需要一个类似于 prev 数组的东西，用于记录当前的 word 是从哪个 word 变更而来的。此时我们可以使用一个 hashmap 来进行记录
 * 
 * 该 hashmap 的 key 为当前 word，value 为父亲节点所组成的列表，也就是通过一个字符变更得到 word 的那些单词。
 * 
 * 而后，我们需要改变队列取数的逻辑，因为需要一层一层的进行遍历，从而填充我们的 hashmap.
 * 
 */
class Solution {
private:
    vector<vector<string>> result;
    void dfs(unordered_map<string, unordered_set<string>> &record, string &current, string &beginWord, string &endWord, vector<string> &path) {
        if (current == beginWord) {
            vector<string> reversed = path;
            reverse(reversed.begin(), reversed.end());
            result.push_back(reversed);
            return ;
        }
        for (string word : record[current]) {
            path.push_back(word);
            dfs(record, word, beginWord, endWord, path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> pool;
        for (string word: wordList)
            pool.insert(word);
                
        if (pool.count(endWord) == 0) return result;

        queue<string> levelQueue;
        unordered_map<string, unordered_set<string>> record;

        levelQueue.push(beginWord);
        record.insert({beginWord, {}});

        bool findLevel = false;

        while (!levelQueue.empty()) {
            int size = levelQueue.size();

            // 我们还是需要在每一层的遍历时整一个 visited 数组，单靠 record 这个 hashmap 无法完成
            unordered_set<string> visited;

            for (int i = 0; i < size; i++) {
                string current = levelQueue.front();
                levelQueue.pop();

                for (int i = 0; i < current.size(); i++) {
                    string temp = current;
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (temp == current || pool.count(temp) == 0) continue;

                        levelQueue.push(temp);
                        visited.insert(temp);
                        record[temp].insert(current);

                        if (temp == endWord) findLevel = true;
                    }
                }
            }

            for (string word: visited)
                pool.erase(word);
            
            if (findLevel) break;
        }

        vector<string> path = {endWord};
        dfs(record, endWord, beginWord, endWord, path);

        return result;
    }
};

