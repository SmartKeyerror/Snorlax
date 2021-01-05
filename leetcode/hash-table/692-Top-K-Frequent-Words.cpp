
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct compare {
    bool operator()(const pair<int, string> &p, const pair<int, string> &q) {
        // first: frequency, second: word
        return p.first < q.first || (p.first == q.first && p.second > q.second);
    }
};

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
