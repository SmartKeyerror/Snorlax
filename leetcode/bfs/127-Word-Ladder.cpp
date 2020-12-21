
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 * 将 beginWord 沿着 wordList 中的单词转换为 endWord，每次至多替换一个字符，求最少操作次数
 * 
 * 状态如何转移题目已经告诉我们了，就是 beginWord 转换成 wordList[i]，然后 wordList[i] 转换为 wordList[i]，直到最终的转换结果为 endWord。
 * 
 * 问题就在于，我们如何寻找下一个状态，例如 beginWord = "hit"， wordList = ["hat", "hot", "haa", "git"]，"hat"、"hot" 和 "git" 都符合只替换一个字符的要求，
 * 但是我们如何在 wordList 找到这些字符?
 * 
 * 现在核心问题就变成了给定一个字符串 S, 找到在 wordList 中只改变一个字符的全部字符串。
 * 有点儿像最短编辑距离，但是用在这里似乎不太合适。所以，还是暴力搜索吧....
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> pool;
        for (string word: wordList)
            pool.insert(word);
        
        if (pool.count(endWord) == 0) return 0;
        if (beginWord == endWord) return 0;

        queue<string> levelQueue;
        unordered_map<string, int> record;

        levelQueue.push(beginWord);
        record.insert({beginWord, 1});

        while (!levelQueue.empty()) {
            string current = levelQueue.front();
            levelQueue.pop();

            // 暴力替换 current 中的每一个字符，于 pool 中查找
            for (int i = 0; i < current.size(); i++) {
                string temp = current;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    if (temp == current) continue;
                    if (pool.count(temp) == 0) continue;
                    if (record.count(temp) != 0) continue;

                    levelQueue.push(temp);
                    record.insert({temp, record[current] + 1});

                    if (temp == endWord) return record[temp];
                }
            }
        }
        return 0;
    }
};
