

#include <vector>
#include <unordered_map>

using namespace std;


/*
 * 1 <= time[i] <= 500，所以 2 <= 2 * time[i] <= 1000，我们只需要从 60 遍历到 960 即可。本质上是一个 Two Sum 问题。
 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < time.size(); i++) {
            for (int j = 60; j <= 960; j += 60) {
                int key = j - time[i];
                if (freq.count(key) != 0) 
                    res += freq[key];
            }
            freq[time[i]] ++;
        }
        return res;
    }
};