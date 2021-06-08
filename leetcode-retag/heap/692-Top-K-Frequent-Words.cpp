
/*
 * Given a non-empty list of words, return the k most frequent elements.
 * 
 * Your answer should be sorted by frequency from highest to lowest. 
 * If two words have the same frequency, then the word with the lower alphabetical order comes first.
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"].
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 和 347.Top K Frequent Elements 问题几乎一模一样，唯一的区别就在于当两个单词的频次相同时，需要按字典序进行排序
 * 
 */
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct compare {
    bool operator()(const pair<int, string> &p, const pair<int, string> &q) {
        // first: frequency, second: word
        return p.first < q.first || (p.first == q.first && p.second > q.second);
    }
};

// 平均时间复杂度 O(nlogK)，最坏 O(nlogn)；空间复杂度 O(K)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (string word: words) count[word] ++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> heap;
        for (auto item : count) heap.push({item.second, item.first});

        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};