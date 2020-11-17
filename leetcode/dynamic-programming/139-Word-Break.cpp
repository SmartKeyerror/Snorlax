
#include <set>
#include <vector>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // 借助 set 进行 O(1) 的查找，视数据量与内存容量使用
        set<string> wordSet;
        for (string word: wordDict)
            wordSet.insert(word);

        // memory[i] 表示字符串 s 中第 i 个字符之前的子串 Break 之后的所有子串均能在 wordDict 找到
        vector<bool> memory(s.size() + 1, false);
        
        memory[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (memory[j] && wordSet.count(s.substr(j, i-j))) {
                    memory[i] = true;
                    break;
                }
            }
        }

        return memory.back();
    }
};