
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
 * 题目需要求解一个字符串中，在内部至少重复一次的、且长度值为 10 的子字符串
 * 
 *  s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 *  ["AAAAACCCCC","CCCCCAAAAA"]
 * 
 * 一个最朴素的方式就是从头开始，取 10 个字符扔进 set 中，判断 set 中是否存在该字串，不存在则从下一个索引取 10 个字符，直至 s[s.size()-10]
 * 时间复杂度为 O(n)， 所需空间大致为 10n，好像能够接受?
 * 
 * Runtime: 68 ms, faster than 93.28% of C++ online submissions for Repeated DNA Sequences.
 * Memory Usage: 19.9 MB, less than 68.33% of C++ online submissions for Repeated DNA Sequences.
 * 
 * 果然，还是能够接受的
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> pool;
        unordered_set<string> result;

        for (int i = 0; i <=s.size() - 10; i ++) {
            string sub = s.substr(i, 10);

            if (sub.size() < 10) break;

            if (pool.find(sub) != pool.end())
                result.insert(sub);
            else
                pool.insert(sub);
        }

        vector<string> res;
        for (auto &item: result) {
            res.push_back(item);
        }

        return res;
    }
};
