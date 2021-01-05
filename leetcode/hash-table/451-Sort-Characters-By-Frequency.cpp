
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        if (s.size() == 0) return s;

        unordered_map<char, int> counter;
        for (auto c : s)
            counter[c] ++;
        
        priority_queue<pair<int, char>> heap;
        for (auto item : counter)
            heap.push({item.second, item.first});
        
        string s = "";
        while (!heap.empty()) {
            int freq = heap.top().first;
            char c = heap.top().second;
            heap.pop();

            while (--freq)
                s += c;
        }
        return s;
    }
};