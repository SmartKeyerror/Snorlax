#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> pool;

        for (auto pair : logs) 
            pool[pair[0]].insert(pair[1]);
        
        vector<int> result(k, 0);

        unordered_map<int, int> freq;

        for (auto &item : pool) 
            freq[item.second.size()] ++;

        for (auto &item : freq)
            result[item.first - 1] = item.second;

        return result;
    }
};