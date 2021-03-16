
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;

        if (n == 0) return result;
    
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int curRank = 1;
        unordered_map<int, int> rank;
        rank[sortedArr[0]] = curRank;

        for (int i = 1; i < n; i++) {
            if (sortedArr[i] != sortedArr[i-1])
                rank[sortedArr[i]] = ++curRank;
        }

        for (int i = 0; i < n; i++) result.push_back(rank[arr[i]]);

        return result;
    }
};